#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq == NULL || pq->heapArray == NULL){
    return NULL
  }
  if(pq->size != 0){
    return pq->heapArray[0].data;
  }
  return NULL;
  
}



void heap_push(Heap* pq, void* data, int priority){



  

}


void heap_pop(Heap* pq){
  pq->size--;
  pq->heapArray[0] = pq->heapArray[pq->size];
  int priority=pq->heapArray[0].priority;
  int x = 1;
  while((x<=pq->size && pq->heapArray[x].priority > priority)||(x+1<=pq->size && pq->heapArray[x+1].priority > priority)){
    heapElem tmp=pq->heapArray[(x-1)/2];
    if(x+1 <= pq->size && pq-> heapArray[x].priority < pq->heapArray[x+1].priority) x++;

    pq->heapArray[(x-1)/2] = pq->heapArray[x];
    pq->heapArray[x]=tmp;
    x = x*2 +1;

  

}

Heap* createHeap(){
  Heap * new = (Heap *)malloc(sizeof(Heap));
  new->heapArray = (heapElem*)malloc(3*sizeof(heapElem));
  new->size =0;
  new->capac=3;
  return new;
  

   return NULL;
}
