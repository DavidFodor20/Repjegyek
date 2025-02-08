#include "Flights_Linked_List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Flight_attach(Flights *first, Flights *new_flight){

    Flights *act=first;
    for(act=first;act->next_flight!=NULL;act=act->next_flight){

    }
 act->next_flight=new_flight;
}


void free_list_flight(Flights *first){
    Flights *act=first; //*next=first->next_flight;
    for(act=first;act!=NULL;act=act->next_flight){
        free(act);
       // act=next;

    }
}


Flights *NewFlights(char* from, char* to, char* date, int id){

    Flights *nf=(Flights*) malloc(sizeof(Flights));
    snprintf(nf->from,sizeof(nf->from),"%s",from);
    snprintf(nf->to,sizeof(nf->to),"%s",to);
    snprintf(nf->date,sizeof(nf->date),"%s",date);
    nf->id=id;
    nf->next_flight = NULL;
    return nf;
}
