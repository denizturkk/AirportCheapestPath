#include "dijkstra.h"
#include <stdio.h>
#include "airport.h"
#include "flight.h"


void dijkstra(struct connected_airport **adjacecnyListHead,int depart,int **listOfDistance,struct min_heap* minHeap,int numberOfAirport)
{



}

void swapMinHeapNode(struct min_heap_node** firstNode, struct min_heap_node** secondNode)
{
    struct min_heap_node* temp = *firstNode;
    *firstNode = *secondNode;
    *secondNode = temp;
}

void minHeapify(struct min_heap* minHeap,int index)
{

    int smallest=index;
    int parent =index;
    int left =(2*index)+1;
    int right =(2*index)+2;

    if(left< minHeap->heapSize && minHeap->arrayOfMinHeap[left]->cost  <  minHeap->arrayOfMinHeap[parent]->cost)
    {
        smallest =left;
    }

    if(right< minHeap->heapSize && minHeap->arrayOfMinHeap[right]->cost < minHeap->arrayOfMinHeap[smallest]->cost)
    {

        smallest = right;
    }

    if(smallest!=index)
    {
        min_heap_node *smallestNode = minHeap->arrayOfMinHeap[smallest];
        min_heap_node *indexNode =minHeap->arrayOfMinHeap[index];

    }





}


//if heap is empty return 0 else it returns 1
int isEmpty(struct min_heap *minHeap)
{
    if(minHeap->capacity==0)
    {
        return 0;

    }

    else
        return 1;


}
