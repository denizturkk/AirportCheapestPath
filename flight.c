#include "flight.h"
#include "airport.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



create_adjacency_list(FILE *fptr,struct airport** headOfAirportArray,struct connected_airport **adjacencyListHead,int numberOfAirport)
{


    struct connected_airport **Head;
    struct connected_airport *tmpPtr;
    Head=&(*adjacencyListHead);

    struct connected_airport *flightNode;


    int idReference;
    char src[4];
    char dest[4];
    int cost;
    int ctr=1;

    while(!feof(fptr))
    {

        //for first direction of flight
       fscanf(fptr,"%4s",src);
       fscanf(fptr,"%4s",dest);
       fscanf(fptr,"%d",&cost);

       flightNode=(struct connected_airport*)malloc(sizeof(struct connected_airport));
       idReference=airport_mapper(src,&(*headOfAirportArray));
       flightNode->depart=airport_mapper(src,&(*headOfAirportArray));
       flightNode->arrival=airport_mapper(dest,&(*headOfAirportArray));
       flightNode->cost=cost;
       flightNode->next=NULL;


       if(Head[idReference]==NULL)
       {
           Head[idReference]=flightNode;


       }
       else
       {
           tmpPtr=Head[idReference];
           while(tmpPtr->next!=NULL)
           {
               tmpPtr=tmpPtr->next;

           }

            tmpPtr->next=flightNode;

       }


        //for another direction of flight

        flightNode=(struct connected_airport*)malloc(sizeof(struct connected_airport));
        idReference=airport_mapper(dest,&(*headOfAirportArray));
        flightNode->depart=airport_mapper(dest,&(*headOfAirportArray));
        flightNode->arrival=airport_mapper(src,&(*headOfAirportArray));
        flightNode->cost=cost;
        flightNode->next=NULL;


        if(Head[idReference]==NULL)
       {
           Head[idReference]=flightNode;
       }
       else
       {
           tmpPtr=Head[idReference];
           while(tmpPtr->next!=NULL)
           {
               tmpPtr=tmpPtr->next;

           }

            tmpPtr->next=flightNode;

       }
        ctr++;
    }


}
void direct_flights(struct connected_airport** Head,int airportId,int numberOfAirports,struct airport *airports)
{
    struct connected_airport* tmp=Head[airportId];
   // printf("%d \n",tmp->arrival);

    printf("\n");
    if(airportId>=numberOfAirports)
    {
        printf("this is not a valid airportId number! \n");
    }

    else if(numberOfAirports>airportId && tmp==NULL)
    {
        printf("there is no flight from this airport\n");
    }

    else
    {
        while(airportId<numberOfAirports && tmp!=NULL)
        {
            printf("from %5s %13s %10s    ---->>>>%5s %13s %10s  cost %d$ \n",airports[airportId].IATA,airports[airportId].city,airports[airportId].country,airports[tmp->arrival].IATA,airports[tmp->arrival].city,airports[tmp->arrival].country,tmp->cost);
            tmp=tmp->next;
        }
        printf("\n");
    }
}
