#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct Reservation{
    char passport[20];
    char name[50];
    int seat_num;
    int fid;
    char menu[10];
    struct Reservation* next_reservation;
}Reservations;

void attach(Reservations *first, Reservations *new_res);

void free_list(Reservations *first);

Reservations *NewReservation(char* passport, char* name, int seat_num, int fid, char* menu);


#endif // LINKED_LIST_H_INCLUDED
