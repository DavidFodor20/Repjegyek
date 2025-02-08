#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "debugmalloc.h"
#include "Linked_List.h"
#include "Flights_Linked_List.h"

int main()
{
   while(Main_menu()==1){

   }
	return 0;
}
int Main_menu(){
    system("cls");


    fflush(stdin);

    int back;
    time_t t;
    time(&t);
    int flights(), search(), reserve(), deleteres(), modify(),display(),service();
    int choice;
    do
	{
    system("cls");
		printf("\n\n\t\t ********************************************************************");
		printf("\n\t\t                   Welcome to David's airline system !                  ");
		printf("\n\t\t ********************************************************************");
		printf("\n\t\t Welcome to my airline system. My airline has flights only in Europe.");
		printf("\n\t\t The planes do not have any classes like business or economical just normal seats.");
		printf("\n\t\t Every flight has 100 seats and no one can book a ticket twice to the same flight.");
		printf("\n\t\t The airline does not keep tabs on every airport in every city");
		printf("\n\t\t So you can just search by city names not airport names. ");
		printf("\n\t\t The airline only shows 20 days of flights");
		printf("\n\t\t Please follow the upcoming instructions: ");
		printf("\n\n\t\t Please enter your choice from below (1-8):");
		printf("\n\t\t 1. Flights");
		printf("\n\t\t 2. Search menu");
		printf("\n\t\t 3. Reservation menu");
		printf("\n\t\t 4. Delete Reservations");
		printf("\n\t\t 5. Modify Reservations");
		printf("\n\t\t 6. Display Reservations");
		printf("\n\t\t 7. Service menu (password required)");
		printf("\n\t\t 8. EXIT");
		printf("\n\t\t Please feel free to contact ");
		printf("\n\t\t Current date and time : %s",ctime(&t));
		printf("\n\t\t Enter your choice and hit ENTER :");
		scanf("%d", &choice);
		fflush(stdin);
		system("cls");
		switch (choice)
		{
		case 1:
			flights();
			break;
		case 2:
			while((back=search_menu())==2){
			}
			break;
		case 3:
			back=reserve();
			break;
        case 4:
			back=deleteres();
			break;
        case 5:
			back=modify();
			break;
        case 6:
			back=display();
			break;
        case 7:
			while((back=service())==3){

			}
			break;
        case 8:
            system("cls");
            printf("\n\t\t Thank you for flying with us!");
			printf("\n\t\t Have a nice day!");
			printf("\n\t\t Best wishes!");
			printf("\n\t\t Press any button to leave the page!");
			getch();
			system("cls");
			back=0;
			break;

		default:
			printf("\n\t Sorry your choice is invalid!");
			printf("\n\t Please choose from 1-8");
			printf("\n\t Do not forget to chose from 1-8");
		}
		getch();
	} while (choice != 8);
	return back;
}
//*************************************************************************************************
int flights()
{
    system("cls");
    char c[100];
    FILE *fp;
    fp=fopen("Test.txt","r");
    if(fp==NULL){
        perror("Could not open file");
        return 1;
    }
    while(!feof(fp)){
       fgets(c,100,fp);
       puts(c);
    }
    fclose(fp);
    printf("\n\n\t\tHit a button to return");
    getch();

    return 1;

}
//**************************************************************************************************
int search_menu()
{
    int back;
    fflush(stdin);
    system("cls");
    int choice;
    printf("\n\n\t\t Please enter your choice from below (1-3):");
    printf("\n\t\t 1. Search by city which your flight is going from and to");
	printf("\n\t\t 2. Search by city which your flight is going from and date");
	printf("\n\t\t 3. Search by destination and date of departure");
	printf("\n\t\t 4. Search by flight ID");
	printf("\n\t\t 5. Back to main menu");
	printf("\n\t\t Please enter your choice and hit ENTER: ");

    scanf("%d", &choice);
		fflush(stdin);
		system("cls");
		switch (choice)
		{
		case 1:
			back=City_search();
			break;
		case 2:
			back=FromAndDate();
			break;
		case 3:
			back=DestinationAndDate();
			break;
        case 4:
			back=ID_search();
			break;
        case 5:
			back=1;
			break;
			}
    return back;
}//**************************************************************************************************
int reserve()
{
   system("cls");
    fflush(stdin);
   char from [10]="test", to [50]="test", date [10]="test";
   int id=0;
   Flights *flight=NewFlights(from,to,date,id),*current;
   FILE *fp;

   fp=fopen("Test.txt","rt");
   if(fp==NULL){
    perror("\n\n\t\tERROR: CANNOT OPEN FILE");

    return 1;
   }
   while(fscanf(fp," %s %s %s %d",from,to,date,&id)!=EOF){
    Flight_attach(flight,NewFlights(from,to,date,id));
   }
   fclose(fp);
   current=flight->next_flight;
    int idd;
    printf("\n\n\t\tType in an ID: ");
    scanf("%d",&idd);
    while(current!=NULL){
            if(idd==current->id){
    printf("\n\n\t\tThe infos of given flight:%s %s %s %d\n",
           current->from,
           current->to,
           current->date,
           current->id);}
    current=current->next_flight;}
    printf("\n\t\tNow for the reservation type in your infos: ");
    printf("\n\t\tPassport number: ");
    char passp[20];
    scanf("%s",passp);
    printf("\n\t\tFirst name: ");
    char namer[50];
    scanf("%s",namer);
    printf("\n\t\tFlight ID: ");
    int f_id;
    scanf("%d",&f_id);
    printf("\n\t\tChoose from menu vegetarian, vegan, normal: ");
    printf("\n\t\tChoice: ");
    char menuu[20];
    scanf("%s",menuu);
    printf("\n\t\tSeat number: ");
    int sn;
    scanf("%d",&sn);

     char passport [10]="dummy", name [50]="dummy", menu[10]="dummy";
   int fid=0, seat_num=0;
   Reservations *res=NewReservation(passport,name,seat_num,fid,menu),*act;
   FILE *fpointer;
   fpointer=fopen("Reservations.txt","rt");
   if(fpointer==NULL){
    perror("\n\n\t\tERROR: CANNOT OPEN FILE");
    return 1;
   }
   while(fscanf(fp," %s %s %d %d %s",passport,name,&seat_num,&fid,menu)!=EOF){
    attach(res,NewReservation(passport,name,seat_num,fid,menu));
   }
   fclose(fp);
   act=res->next_reservation;
   while(act!=NULL){
   }
    free_list_flight(flight);
    return 1;
}//**************************************************************************************************
int deleteres(void)
{
    system("cls");
    printf("alma");
    getch();
    return 1;
}//**************************************************************************************************
int modify(void)
{
    system("cls");
    printf("alma");
    getch();
    return 1;
}//**************************************************************************************************
int display(void)
{
    system("cls");
    fflush(stdin);
   char passport [10]="dummy", name [50]="dummy", menu[10]="dummy";
   int fid=0, seat_num=0;
   Reservations *res=NewReservation(passport,name,seat_num,fid,menu),*current;
   FILE *fp;
   fp=fopen("Reservations.txt","rt");
   if(fp==NULL){
    perror("\n\n\t\tERROR: CANNOT OPEN FILE");
    return 1;
   }
   while(fscanf(fp," %s %s %d %d %s",passport,name,&seat_num,&fid,menu)!=EOF){
    attach(res,NewReservation(passport,name,seat_num,fid,menu));
   }
   fclose(fp);
   current=res->next_reservation;

   while(current!=NULL){
    printf("\n\n\t\t%s %s %d %d %s\n",
           current->passport,
           current->name,
           current->seat_num,
           current->fid,
           current->menu);
    current=current->next_reservation;
   }
   free_list(res);

    getch();
    return 1;
}//**************************************************************************************************
int service(void)
{

    system("cls");
    int choice;
   if((choice=password())==1){
        return 1;
        }

      system("cls");
    fflush(stdin);
   char passport [10]="dummy", name [50]="dummy", menu[10]="dummy";
   int fid=0, seat_num=0;
   Reservations *res=NewReservation(passport,name,seat_num,fid,menu),*current;
   FILE *fp;
   fp=fopen("Reservations.txt","rt");
   if(fp==NULL){
    perror("\n\n\t\tERROR: CANNOT OPEN FILE");
    return 1;
   }
   while(fscanf(fp," %s %s %d %d %s",passport,name,&seat_num,&fid,menu)!=EOF){
    attach(res,NewReservation(passport,name,seat_num,fid,menu));
   }
   fclose(fp);
   current=res->next_reservation;
    int vegetarian=0,vegan=0,normal=0;
    int idd;
    printf("\n\n\t\t Type in the ID of the flight:");
    scanf("%d",&idd);
   while(current!=NULL){
    if(idd==current->fid){
        if(strcmp("vegetarian",current->menu)==0)
            vegetarian++;
        if(strcmp("vegan",current->menu)==0)
            vegan++;
        if(strcmp("normal",current->menu)==0)
            normal++;
    }
    current=current->next_reservation;
   }
   printf("\n\n\t\tYou will need %d vegetarian meals",vegetarian);
   printf("\n\t\tYou will need %d vegan meals",vegan);
   printf("\n\t\tYou will need %d normal meals",normal);
   free_list(res);

    getch();
    return 1;
}//**************************************************************************************************
int password(void)
{
    char pass[15]= {0};

    char check[15]="password";
    int i=0,j;
    printf("\n\n\tPlease write the password here\n");
    printf("\n\n\tYou have three chances to get the password right\n ");
    for(j=0; j<3; j++)
    {
        i=0;
        printf("\n\n\tpassword:");
        pass[0]=getch();
        while(pass[i]!='\r')
        {
            if(pass[i]=='\b')
            {
                i--;
                printf("\b");
                printf(" ");
                printf("\b");
                pass[i]=getch();
            }
            else
            {
                printf("*");
                i++;
                pass[i]=getch();
            }
        }

        pass[i]='\0';
        if(strcmp(pass,check)==0){
                printf("\n\n\t\t LOGIN SUCCESSFULL");
                printf("\n\n\t\t HIT A BUTTON TO CONTINUE");
                getch();
                return 3;

        }

    else{
   printf("\n\n\t\t Please try again");
    }


    }
    printf("\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO RETURN...");
    return 1;
    }

    //**************************************************************************************************
int City_search(void){


    system("cls");
    fflush(stdin);
   char from [10]="dummy", to [50]="dummy", date [10]="dummy";
   int id=0;
   Flights *flight=NewFlights(from,to,date,id),*current;
   FILE *fp;

   fp=fopen("Test.txt","rt");
   if(fp==NULL){
    perror("\n\n\t\tERROR: CANNOT OPEN FILE");

    return 1;
   }
   while(fscanf(fp," %s %s %s %d",from,to,date,&id)!=EOF){
    Flight_attach(flight,NewFlights(from,to,date,id));
   }
   fclose(fp);
   current=flight->next_flight;
   char newf [20] ;
   char newd[20] ;
   scanf("%s",newf);
   scanf("%s",newd);
   while(current!=NULL){
       if(strcmp(newf,current->from)==0&&strcmp(newd,current->to)==0){
 printf("\n\n\t\t%s %s %s %d\n",
           current->from,
           current->to,
           current->date,
           current->id);
           }
           current=current->next_flight;
  }
   free_list_flight(flight);

    getch();
    return 2;
}
 //**************************************************************************************************
int FromAndDate(){

    system("cls");
    fflush(stdin);
   char from [10]="dummy", to [50]="dummy", date [10]="dummy";
   int id=0;
   Flights *flight=NewFlights(from,to,date,id),*current;
   FILE *fp;
   fp=fopen("Test.txt","rt");
   if(fp==NULL){
    perror("\n\n\t\tERROR: CANNOT OPEN FILE");
    return 1;
   }
   while(fscanf(fp," %s %s %s %d",from,to,date,&id)!=EOF){
    Flight_attach(flight,NewFlights(from,to,date,id));
   }
   fclose(fp);
   current=flight->next_flight;
   char newf [20] ;
   char d[20] ;
   scanf("%s",newf);
   scanf("%s",d);
   while(current!=NULL){
       if(strcmp(newf,current->from)==0&&strcmp(d,current->date)==0){
 printf("\n\n\t\t%s %s %s %d\n",
           current->from,
           current->to,
           current->date,
           current->id);

           }
           current=current->next_flight;
  }
   free_list_flight(flight);

    getch();


    return 2;

}
//**************************************************************************************************
int DestinationAndDate(){

    system("cls");
    fflush(stdin);
   char from [10]="dummy", to [50]="dummy", date [10]="dummy";
   int id=0;
   Flights *flight=NewFlights(from,to,date,id),*current;
   FILE *fp;
   fp=fopen("Test.txt","rt");
   if(fp==NULL){
    perror("\n\n\t\tERROR: CANNOT OPEN FILE");
    return 1;
   }
   while(fscanf(fp," %s %s %s %d",from,to,date,&id)!=EOF){
    Flight_attach(flight,NewFlights(from,to,date,id));
   }
   fclose(fp);
   current=flight->next_flight;
   char newd [20] ;
   char d[20] ;
   scanf("%s",newd);
   scanf("%s",d);
   while(current!=NULL){
       if(strcmp(newd,current->to)==0&&strcmp(d,current->date)==0){
 printf("\n\n\t\t%s %s %s %d\n",
           current->from,
           current->to,
           current->date,
           current->id);

           }
           current=current->next_flight;
  }



   free_list_flight(flight);

    getch();


    return 2;
}
//**************************************************************************************************
int ID_search(){

      system("cls");
    fflush(stdin);
   char from [10]="dummy", to [50]="dummy", date [10]="dummy";
   int id=0;
   Flights *flight=NewFlights(from,to,date,id),*current;
   FILE *fp;
   fp=fopen("Test.txt","rt");
   if(fp==NULL){
    perror("\n\n\t\tERROR: CANNOT OPEN FILE");
    return 1;
   }
   while(fscanf(fp," %s %s %s %d",from,to,date,&id)!=EOF){
    Flight_attach(flight,NewFlights(from,to,date,id));
   }
   fclose(fp);
   current=flight->next_flight;
   int idd;
   scanf("%d",&idd);
   while(current!=NULL){
       if(idd==current->id){
 printf("\n\n\t\t%s %s %s %d\n",
           current->from,
           current->to,
           current->date,
           current->id);
           }
           current=current->next_flight;
  }
   free_list_flight(flight);

    getch();


    return 2;
    }
