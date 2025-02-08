#ifndef FLIGHTS_LINKED_LIST_H_INCLUDED
#define FLIGHTS_LINKED_LIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct Flight{
    char from[30];
    char to[30];
    char date[20];
    int id;
    struct Flight* next_flight;
}Flights;


void Flight_attach(Flights *first, Flights *new_flight);

void free_list_flight (Flights *first);

Flights *NewFlights(char* from, char* to, char* date, int id);

#endif // FLIGHTS_LINKED_LIST_H_INCLUDED
