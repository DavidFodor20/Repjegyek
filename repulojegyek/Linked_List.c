#include "Linked_List.h"
#include <stdio.h>
#include <stdlib.h>

void attach(Reservations *first, Reservations *new_res){

    Reservations *act=first;
    for(act=first;act->next_reservation!=NULL;act=act->next_reservation){

    }
    act->next_reservation=new_res;
}


void free_list(Reservations *first){
    Reservations *act=first; //*next=first->next_reservation;
    for(act=first;act!=NULL;act=act->next_reservation){
           // ki kene printelni hogy lassam
        free(act);
        //act=next;
    }
}


Reservations *NewReservation(char* passport, char* name, int seat_num, int fid, char* menu){

    Reservations *newres=(Reservations*) malloc(sizeof(Reservations));
    snprintf(newres->passport,sizeof(newres->passport),"%s",passport);
    snprintf(newres->name,sizeof(newres->name),"%s",name);
    newres->seat_num=seat_num;
    newres->fid=fid;
    snprintf(newres->menu,sizeof(newres->menu),"%s",menu);
    newres->next_reservation = NULL;
    return newres;
}
