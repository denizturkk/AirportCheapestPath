#ifndef dijkstra_h_
#define dijkstra_h_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airport.h"
#include "flight.h"

typedef struct min_heap_node
{
    int airportId;
    int via;
    int cost;

}min_heap_node;

typedef struct min_heap
{
    int capacity;
    int heapSize;
    int* position;
    struct min_heap_node **arrayOfMinHeap;

}min_heap;


void dijkstra( struct connected_airport **adjacencyListHead,int depart ,int **listOfDistance,struct min_heap*,int numberOfAirport);
void swapMinHeapNode(struct min_heap_node** firstNode, struct min_heap_node** secondNode);
int isEmpty(struct min_heap *minHeap);

#endif // dijkstra_h_
