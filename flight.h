#ifndef flight_h_
#define flight_h_
#include <string.h>
#include <stdio.h>
#include "airport.h"
#include "dijkstra.h"

typedef struct flight
{
    char src[4];
    char dest[4];
    int cost;

}flight;

typedef struct connected_airport
{
    int depart;
    int arrival;
    int cost;
    struct connected_airport *next;

}connected_airport;


void create_adjacency_list(FILE *fptr,struct airport** headOfAirportArray,struct connected_airport **adjacencyListHead,int numberOfAirport);


#endif // flight_h_
