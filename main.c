#include <stdio.h>
#include <stdlib.h>
#include "airport.h"
#include <string.h>
#include "flight.h"
#include "dijkstra.h"
#include <limits.h>



int main()
{


    FILE *fptr;
    fptr=fopen("airports.txt","r");


    if(fptr==NULL)
    {
        printf("airports.txt could not be opened\n");
        exit(1);

    }

    int numberOfAirport=airport_counter(fptr);
    airport airports[numberOfAirport];


    fill_list_of_airports(fptr,&airports,numberOfAirport);

    fptr =fopen("flights.txt","r");

    if(fptr==NULL)
    {
         printf("flights.txt could not be opened! \n");
         exit(1);
    }

    //An array of pointer for adjacency list(airport grap)
    struct connected_Airport *adjacencyListHead[numberOfAirport];

   //initialize pointers with null
   for(int i =0;i<17 ;i++)
   {
       adjacencyListHead[i]=NULL;
   }

    create_adjacency_list(fptr,&airports,&adjacencyListHead,numberOfAirport);

    //to keep results
    int distances[numberOfAirport];

    //to create a heap for dijkstra
    struct min_heap minHeap;

    //initializing the heap
    minHeap.heapSize=numberOfAirport;
    minHeap.capacity=0;

    //memory allocation for min heap and position arrray
    minHeap.arrayOfMinHeap=(struct min_heap_node*)malloc(sizeof(struct min_heap_node)*numberOfAirport);
    minHeap.position=(int*)malloc(sizeof(int)*numberOfAirport);

    //initialize the minheap's all vertice's distances with maxvalue of int
    //initialize the distance's with using INT_MAX
    for(int i=0; i<numberOfAirport ;i++)
    {
        minHeap.arrayOfMinHeap[i]->cost=INT_MAX;
        distances[i]=INT_MAX;
        minHeap.position[i]=i;


    }

    int depart=0;

    dijkstra(&adjacencyListHead,depart,&distances,&minHeap,numberOfAirport);




    return 0;
}
