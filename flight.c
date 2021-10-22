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
    }
}
