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
    return NULL;
  }
  if(pq->size != 0){
    return pq->heapArray[0].data;
  }
  return NULL;
  
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->size+1 > pq->cap){

    pq->heapArray = (heapElem*)realloc(pq->heapArray,pq->capac*sizeof(heapElem));
    pq->cap = ((pq->cap)*2)+1;
  }
  int x = pq->size;
  while(x>0 && pq->heapArray[(x-1)/2].priority < priority)
  {
    pq->heapArray[x] = pq->heapArray[(x-1)/2];
    aux = (x-1)/2;
  }
  pq->heapArray[x].data = data;
  pq->heapArray[x].priority = priority;
  pq->size++;

}


void heap_pop(Heap* pq){
  pq->size--;
  pq->heapArray[0]=pq->heapArray[pq->size];
  int x = 1;
  int priority= pq->heapArray[0].priority;
  while((x <= pq->size && pq->heapArray[x].priority > priority) || (x+1 <= pq->size && pq->heapArray[x+1].priority > priority))
  {
    heapElem tmp = pq->heapArray[(x-1)/2];
    if(x+1 <= pq->size && pq->heapArray[aux].priority < pq->heapArray[x+1].priority) x++;
    pq->heapArray[(x-1)/2] = pq->heapArray[x];
    pq->heapArray[x] = tmp;
    x = (x*2)+1;
    
  }
}

Heap* createHeap(){
  Heap * pq = (Heap *)calloc(1,sizeof(Heap));
  pq->heapArray = (heapElem*)calloc(pq->capac,sizeof(heapElem));
  pq->size =0; // total de elementos en el heap
  pq->capac=3; //capacidad del heap
  return pq;
  
}
