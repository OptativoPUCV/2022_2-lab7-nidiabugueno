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
  if(pq->size==0) return NULL;
  return pq->heapArray[0].data;
  
}



void heap_push(Heap* pq, void* data, int priority){
   if (pq->capac == pq->size)
   {
      heapElem* tmpArray = (heapElem*) calloc (pq->capac, sizeof(heapElem));
      for (int i = 0 ; i < pq->size ; i = i + 1)
      {
        tmpArray[i] = pq->heapArray[i];    
      }
      pq->capac = (pq->capac * 2) + 1;
      pq->heapArray = (heapElem*) calloc (pq->capac, sizeof(heapElem));
      for (int i = 0 ; i < pq->size ; i = i + 1)
      {
        pq->heapArray[i] = tmpArray[i];    
      }
   }

   int pos = pq->size;
   pq->heapArray[pos].data = data;
   pq->heapArray[pos].priority = priority;
  
   swap(pq, pos);
   pq->size = pq->size + 1;
   if (pq->heapArray[pos].priority > pq->heapArray[(pos-1)/2].priority)
      {
         aux->data = pq->heapArray[(pos-1)/2].data;
         aux->priority = pq->heapArray[(pos-1)/2].priority;
         pq->heapArray[(pos-1)/2] = pq->heapArray[pos]; 
         pq->heapArray[pos].data = aux->data;
         pq->heapArray[pos].priority = aux->priority;
         pos = (pos-1)/2;
      }
      else
      {
        return;
      }
   } 
  

}


void heap_pop(Heap* pq){
  size--;
  array[0] = array[pq->size];

  

}

Heap* createHeap(){
  Heap * new = (Heap *)malloc(sizeof(Heap));
  new->heapArray = (heapElem*)malloc(3*sizeof(heapElem));
  new->size =0;
  new->capac=3;
  return new;
  

   return NULL;
}
