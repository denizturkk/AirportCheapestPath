#ifndef airport_h_
#define airport_h_

#include "flight.h"
#include <string.h>

typedef struct airport
{
 char IATA[4];
 char city[15];
 char country[15];
 int airportId;

}airport;

//takes the informations of airports reading txt file then puts them on the given array
void fill_list_of_airports(FILE *fptr, struct airport **airports,int numberOfAirport);

//takes a file pointer opened before,count the rows then put the pointer
//on the beginning of the file
int airport_counter(FILE *fptr);

//returns the index of given airport's IATA code
//to work with airports id instead of strings
int airport_mapper(char IATA[4],struct airport** headOfArray);

//list all airports in the network
void list_All_Airports(struct airport *airports,int numberOfAirport);

#endif // airport_h_
