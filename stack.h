#ifndef stack_h_
#define stack_h_
#include "dijkstra.h"

void push(struct connected_airport** rear,int arrival,struct result* results);
void route(int startPoint,int endPoint,struct result* results,struct airport* airports);
void printRoute(struct connected_airport* head,int numberOfNodes,struct airport* airports);



#endif // stack_h_
