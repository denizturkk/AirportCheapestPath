#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include "flight.h"
#include "airport.h"


void push(struct connected_airport** rear,int arrival,struct result* results)
{
    (*rear)->next=(struct connected_airport*)malloc(sizeof(struct connected_airport));
    (*rear)=(*rear)->next;
    (*rear)->arrival=arrival;
    (*rear)->depart=results[arrival].via;
    (*rear)->cost=results[arrival].distance-results[results[arrival].via].distance;
    (*rear)->next=NULL;
    //printf("rear depart %d arrival %d \n",*rear->depart,*rear->arrival);


}


void route(int startPoint,int endPoint,struct result* results,struct airport* airports)
{
    int lastDepart;
    int lastArrival;
    int flightNumberCounter=0;
    struct connected_airport* head=(struct connected_airport*)malloc(sizeof(struct connected_airport));
    struct connected_airport* rear;
    rear=head;
    head->arrival=endPoint;
    head->depart=results[endPoint].via;
    head->cost=results[endPoint].distance-results[results[endPoint].via].distance;
    head->next=NULL;
    flightNumberCounter++;


    while(rear->depart!=startPoint)
    {
        //printf("whileda rearýn departý %d  arrivalý %d \n",rear->depart,rear->arrival);

        push(&rear,rear->depart,results);
        flightNumberCounter++;
    }

    printf("from %5d %5s %13s ---->>>>> %5d %13s %13s \n\n",startPoint,airports[startPoint].IATA,airports[startPoint].city,endPoint,airports[endPoint].IATA,airports[endPoint].city);
    printf("total cost is %d$ and  ",results[endPoint].distance);
    printRoute(head,flightNumberCounter,airports);

}
void printRoute(struct connected_airport* head,int numberOfNodes,struct airport* airports)
{
   // printf("numer of nodes %d",numberOfNodes);

    struct connected_airport* arrayOfAddress[numberOfNodes];
    struct connected_airport* tmp;
    tmp=head;
    int counter=0;
    int scounter=1;

    while(tmp!=NULL && counter<numberOfNodes)
    {
        arrayOfAddress[counter]=tmp;
        tmp=tmp->next;
        counter++;
    }
    printf("you have %d flights to arrive the destination airport for cheapest trip \n\n\n",counter);

   // printf("conter %d",counter);

    struct connected_airport* tmpPtr;
    for(int i=0;i<counter;counter--)
    {
        tmpPtr=arrayOfAddress[counter-1];
        int departt=tmpPtr->depart;
        int arrivall=tmpPtr->arrival;

        printf("%d.flight:%5d %5s %13s    ----->>>>>  %5d %5s %13s cost is %d$ \n",scounter,departt,airports[departt].IATA,airports[departt].city,arrivall,airports[arrivall].IATA,airports[arrivall].city,arrayOfAddress[counter-1]->cost);
        free(arrayOfAddress[counter-1]);

        scounter++;


    }



}

