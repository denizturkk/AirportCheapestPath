#include <stdio.h>
#include "airport.h"



int airport_counter(FILE *fptr)
{
    int numberOfAirport=1;
        char c;
        for (c = getc(fptr); c != EOF; c = getc(fptr))
        {
             if (c == '\n') // Increment count if this character is newline
            numberOfAirport = numberOfAirport + 1;

        }

        rewind(fptr);
        return numberOfAirport;

}

void fill_list_of_airports(FILE *fptr, struct airport **airports,int numberOfAirport)
{
        struct airport* airport;
        airport =&(*airports);
        int counter=0;
        char IATA [4];
        char city[15];
        char country[15];


       while(!feof(fptr))
       {
            fscanf(fptr,"%4s",IATA);
            fscanf(fptr,"%15s",city);
            fscanf(fptr,"%15s",country);


            airport[counter].airportId=counter;
            strcpy(airport[counter].IATA,IATA);
            strcpy(airport[counter].city,city);
            strcpy(airport[counter].country,country);

            counter++;

       }
        fclose(fptr);

}

int airport_mapper(char IATA[4],struct airport** headOfArray)
{
    struct airport *airports;
    airports=&(*headOfArray);

    int x =0;
    while(strcmp(IATA,airports[x].IATA)!=0)
    {
        x++;
    }

    return x;


}




