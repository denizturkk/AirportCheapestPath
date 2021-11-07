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
    int distance;

}min_heap_node;

typedef struct min_heap
{
    int capacity;
    int heapSize;
    int* position;
    struct min_heap_node **arrayOfMinHeap;

}min_heap;

typedef struct result
{
  int distance;
  int via;

}result;

//needed operations for dijkstra algorithm
struct min_heap_node* extractMin(struct min_heap* minHeap);
int isInMinHeap(struct min_heap* min_heap,int airportId);
void dijkstra( struct connected_airport **adjacencyListHead,int src ,struct result *listOfDistance,struct min_heap*,int numberOfAirport);
void swapMinHeapNode(struct min_heap_node* firstNode, struct min_heap_node* secondNode);
int isEmpty(struct min_heap *minHeap);
void minHeapify(struct min_heap* minHeap,int index);
void decreaseKey(struct min_heap* minHeap,int airportId, int dist);


#endif // dijkstra_h_
