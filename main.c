#include <stdio.h>
#include <stdlib.h>
#include "airport.h"
#include <string.h>
#include "flight.h"
#include "dijkstra.h"
#include <limits.h>
#include "stack.h"



int main()
{


    FILE *fptr;
    fptr=fopen("airports.txt","r");


    if(fptr==NULL)
    {
        printf("airports.txt could not be opened\n");
        exit(1);

    }

    //to get number of airports
    int numberOfAirport=airport_counter(fptr);

    //create an array with size of number of airports
    airport airports[numberOfAirport];
    printf("number of airport %d\n",numberOfAirport);

    //fills the airport array
    fill_list_of_airports(fptr,&airports,numberOfAirport);
    //list_All_Airports(&airports,numberOfAirport);

    //opens the file
    fptr =fopen("flights.txt","r");
    if(fptr==NULL)
    {
         printf("flights.txt could not be opened! \n");
         exit(1);

    }

    //An array of (adjacency list)connected_airport pointer to create a graph
    struct connected_Airport *adjacencyListHead[numberOfAirport];

   for(int i =0;i<numberOfAirport ;i++)
   {
       *(adjacencyListHead+i)=NULL;
   }

    //creates the graph through array of adj list pointers and airport list
    create_adjacency_list(fptr,&airports,&adjacencyListHead,numberOfAirport);
///////////////////////////////
    struct connected_airport* asd;




    //to keep costs results
    struct result distances[numberOfAirport];


    //to create a heap for dijkstra algorithm
    struct min_heap minHeap;

    //initializing the heap
    minHeap.heapSize=numberOfAirport;
    minHeap.capacity=numberOfAirport;

    //memory allocation for min heap and position array
    minHeap.arrayOfMinHeap=malloc(sizeof(struct min_heap_node)*numberOfAirport);
    minHeap.position=(int*)malloc(sizeof(int)*numberOfAirport);

    struct min_heap_node* tmp;
    tmp=minHeap.arrayOfMinHeap;

    //initialize the minheap's all vertice's distances with maxvalue of int(infinite)
    //initialize the distance's with using INT_MAX
  /*  for(int i=0; i<numberOfAirport ;i++)
    {
        tmp[i].airportId=i;
        tmp[i].distance=INT_MAX;
        tmp[i].via=INT_MAX;
        distances[i].distance=INT_MAX;
        distances[i].via=INT_MAX;
        minHeap.position[i]=i;

    }
*/

    printf("---------SHORTEST PATH ALGORITHM------------\n\n\n");

    //switch case operations

    int choice=3;
    int schoice=1;
    int airportId;
    int sAirportId;



    while(choice!=6)
    {
        printf("\n");
        printf("1:List all airports in the network\n");
        printf("2:list all the direct flights from an airport \n");
        printf("3:list all direct flights of all airports \n");
        printf("4:list the min-cost path from an airport to destination airport and its cost\n");
        printf("5:list all min-cost flights from an airport to all another airports in the network\n");
        printf("6:exit\n");

        printf("please make a choice \n\n");
        scanf("%d",&choice);

        //reinitialize the data structures
        minHeap.heapSize=numberOfAirport;
        minHeap.capacity=numberOfAirport;
        for(int i=0; i<numberOfAirport ;i++)
        {
            tmp[i].airportId=i;
            tmp[i].distance=INT_MAX;
            tmp[i].via=INT_MAX;
            distances[i].distance=INT_MAX;
            distances[i].via=INT_MAX;
            minHeap.position[i]=i;

        }

        switch(choice)
        {

           case 1:

                list_All_Airports(&airports,numberOfAirport);
                printf("\n");
                break;
           case 2:
               printf("\n\nenter the airportid from which you want to see the flights \n\n");
               scanf("%d",&airportId);
               direct_flights(adjacencyListHead,airportId,numberOfAirport,airports);
               break;
           case 3:
                for(int i=0;i<numberOfAirport;i++)
                {
                    direct_flights(adjacencyListHead,i,numberOfAirport,airports);
                }
            break;

           case 4:
                    printf("enter the depart airport\n");
                    scanf("%d",&airportId);

                    printf("enter the  destination airport\n");
                    scanf("%d",&sAirportId);
                     dijkstra(&adjacencyListHead,airportId,distances,&minHeap,numberOfAirport);
                     route(airportId,sAirportId,distances,airports);

            break;

                case 5:

                  printf("\nfrom which airport you want to flight \n");
                  scanf("%d",&airportId);
                  dijkstra(&adjacencyListHead,airportId,distances,&minHeap,numberOfAirport);
                  for(int i=0 ;i<numberOfAirport;i++)
                  {
                    printf("from %d %5s %13s to %5d %10s %13s cheapest paths cost is equal to %d$ \n",airportId,airports[airportId].IATA,airports[airportId].city,i,airports[i].IATA,airports[i].city,distances[i].distance );
                  }

                    schoice=1;
                    while(schoice!=2)
                    {
                        printf("\n\nplease make a choice \n\n");
                        printf("\n1:if you want to learn the shortest path through %s to any airport on the list\n",airports[airportId].IATA);
                        printf("2:exit to main menu\n");
                        scanf("%d",&schoice);

                        switch(schoice)
                        {
                             case 1:
                                    printf("\n please enter the arrival airport \n ");
                                    scanf("%d",&sAirportId);
                                    route(airportId,sAirportId,distances,airports);
                            break;

                            case 2:
                                    schoice =2;
                            break;

                            default:
                                printf("this operation is not valid \n");
                            break;
                        }
                    }
            break;

           case 6:
                choice=6;
            break;

           default:
           printf("\nthis is not a valid operation \n");
            break;

        };

    }
    return 0;
}
