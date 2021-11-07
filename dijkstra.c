#include "dijkstra.h"
#include <stdio.h>
#include "airport.h"
#include "flight.h"
#include "dijkstra.h"


void dijkstra(struct connected_airport **adjacencyListHead,int depart,struct result *listOfDistance,struct min_heap* minHeap,int numberOfAirport)
{
    struct connected_airport **graph=adjacencyListHead;

    struct connected_airport* tmpp;


    struct min_heap_node* mHeapArray;
    mHeapArray=minHeap->arrayOfMinHeap;

    minHeap->position[depart] = depart;
    listOfDistance[depart].distance = 0;
    listOfDistance[depart].via=depart;



    mHeapArray[depart].distance=listOfDistance[depart].distance;
    mHeapArray[depart].via=listOfDistance[depart].via;
    mHeapArray[depart].airportId =depart;

    //printf("before dk %d  %d %d \n",mHeapArray[0].distance,mHeapArray[0].airportId,mHeapArray[0].via);

   // printf("%d heapsize",minHeap->heapSize);

    decreaseKey(minHeap,depart, listOfDistance[depart].distance);

    // printf("after dk %d  %d %d \n",mHeapArray[0].distance,mHeapArray[0].airportId,mHeapArray[0].via);


    while (!isEmpty(minHeap))
    {
        /*
        for(int i=0 ;i<numberOfAirport;i++)
        {
            printf("%d.Node, adress %d %d %d %d \n",i,mHeapArray+i,mHeapArray[i].airportId,mHeapArray[i].distance,mHeapArray[i].via);

        }
        */

        // Extract the vertex with
        // minimum distance value
        struct min_heap_node* minHeapNode =extractMin(minHeap);

        // Store the extracted vertex number
        int extractedId = minHeapNode->airportId;

        // Traverse through all adjacent
        // vertices of the extracted
        // vertex and update
        // their distance values
        struct connected_airport* adjacentAirports =graph[extractedId];


        while (adjacentAirports!= NULL)
        {
            //id number of the adjacent airport of extracted airport
            int adjacentId = adjacentAirports->arrival;

            //if the neighbor of extracted vertex is in minheap(If shortest distance to v is not finalized yet)
            //if extracted vertex distance is not infinity,)
            //distance to v through u is less than its previously calculated distance

            if (isInMinHeap(minHeap, adjacentId) && listOfDistance[extractedId].distance != INT_MAX && adjacentAirports->cost + listOfDistance[extractedId].distance < listOfDistance[adjacentId].distance)
            {

                listOfDistance[adjacentId].distance = listOfDistance[extractedId].distance + adjacentAirports->cost;
                listOfDistance[adjacentId].via=extractedId;

               //listOfDistance[v].via=listOfDistance[u].via;

                // update distance
                // value in min heap also
                decreaseKey(minHeap, adjacentId, listOfDistance[adjacentId].distance);

            }
            adjacentAirports = adjacentAirports->next;
        }


    }


}


struct min_heap_node* extractMin(struct min_heap* minHeap)
{

    if (isEmpty(minHeap))
    {
         return NULL;
    }

    struct min_heap_node* mHeapArray;
    mHeapArray=minHeap->arrayOfMinHeap;

    // Store the first airport node (root node)
    struct min_heap_node* rootNode =&mHeapArray[0];

    // Replace root node with last node
    struct min_heap_node* lastNode =&(mHeapArray[minHeap->heapSize - 1]);

    struct min_heap_node tmpNode=*rootNode;

     mHeapArray[0] = *lastNode;

    // Update position of last node
    minHeap->position[tmpNode.airportId] = (minHeap->heapSize)-1;


    minHeap->position[lastNode->airportId] = 0;

     mHeapArray[minHeap->heapSize - 1] = tmpNode;

     // Reduce heap size and heapify root
    minHeap->heapSize=minHeap->heapSize-1;

    minHeapify(minHeap, 0);

    return &(mHeapArray[minHeap->heapSize]);
}

//changes the given airport's distance value in the minHeapArray
//since the priority could be changed in min_heap then the function
//look if minheap array corresponds to min heap requirements if its
//not while loop continue to change the nodes with its parent node
void decreaseKey(struct min_heap* minHeap,int airportId, int dist)
{
 //decreaseKey(minHeap,depart, listOfDistance[depart].distance);

    struct min_heap_node* mHeapArray;
    mHeapArray=minHeap->arrayOfMinHeap;

    // Get the position(index)of airport in  heap array using position array
    int index = minHeap->position[airportId];

    // Get the struct through arrayofMinHeap and update its dist value
     mHeapArray[index].distance = dist;

    while (index>0 && mHeapArray[index].distance < mHeapArray[(index - 1) / 2].distance)
    {

        // Swap the airports
        //first the positions information will be changed on position array
        minHeap->position[mHeapArray[index].airportId] =(index-1)/2;
        minHeap->position[mHeapArray[(index-1)/2].airportId] = index;


        //then the positions itself will be changed on minheaparray
        swapMinHeapNode(&(mHeapArray[index]),&(mHeapArray[(index - 1) / 2]));
        // move to parent index
       // printf(" ------------dk index %d airport id %d \n",index,mHeapArray[(index - 1) / 2].airportId);

       // printf(" ----------indeks %d \n ",index);
       /*
        printf("after swap 0. pos %d \n",minHeap->position[0]);
        printf("after swap 1. pos %d \n",minHeap->position[1]);
        printf("after swap 3. pos %d \n",minHeap->position[3]);

         printf("after swap 0.mheapindex %d %d %d \n",mHeapArray[0].airportId,mHeapArray[0].distance ,mHeapArray[0].via);
         printf("after swap 1.mheapindex %d %d %d \n",mHeapArray[1].airportId,mHeapArray[1].distance ,mHeapArray[1].via);
         printf("after swap 3.mheapindex %d %d %d \n",mHeapArray[3].airportId,mHeapArray[3].distance ,mHeapArray[3].via);
         printf("\n");
        */
        index = (index - 1) / 2;
    }
}

void swapMinHeapNode(struct min_heap_node* firstNode, struct min_heap_node* secondNode)
{
    //store the first node infos in temp;
    struct min_heap_node temp;
    temp.airportId = firstNode->airportId;
    temp.distance = firstNode->distance;
    temp.via =      firstNode->via;

    //assign sec node infos to the first node infos
    firstNode->airportId =secondNode->airportId;
    firstNode->distance =secondNode->distance;
    firstNode->via =secondNode->via;

    (secondNode)->airportId= temp.airportId;
    (secondNode)->distance= temp.distance;
    (secondNode)->via= temp.via;

}


void minHeapify(struct min_heap* minHeap,int index)
{
    //printf("index %d minheapify \n",index);
    int smallest=index;
    int parent =index;
    int left =(2*index)+1;
    int right =(2*index)+2;


    struct min_heap_node* mHeapArray;
    mHeapArray=minHeap->arrayOfMinHeap;

    if(left< minHeap->heapSize && mHeapArray[left].distance  <  mHeapArray[parent].distance)
    {
        smallest =left;

    }

    if(right< minHeap->heapSize && mHeapArray[right].distance < mHeapArray[smallest].distance)
    {

        smallest = right;
    }



    if(smallest!=index)
    {
        min_heap_node *smallestNode = &mHeapArray[smallest];
        min_heap_node *indexNode =&mHeapArray[index];

        //change the position of  airports that will be swapped
        minHeap->position[smallestNode->airportId]=index;
        minHeap->position[indexNode->airportId]=smallest;

        //swaps the airports on minHeap Priority queue
        swapMinHeapNode(&(mHeapArray[smallest]),&(mHeapArray[index]));
        minHeapify(minHeap, smallest);

    }


}


int isInMinHeap(struct min_heap* min_heap,int airportId)
{
    if((min_heap)->heapSize > (min_heap)->position[airportId])
    {
        return 1;
    }
    else
    {
         return 0;
    }

}

//if heap is empty return 1 else it returns 0
int isEmpty(struct min_heap *minHeap)
{
    if(minHeap->heapSize==0)
    {
        return 1;
    }
    else
        return 0;
}
