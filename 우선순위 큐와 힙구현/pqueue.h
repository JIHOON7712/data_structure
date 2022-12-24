#ifndef __PQUEUE__
#define __PQUEUE__
#define LEN 100
#define TRUE 1
#define FALSE 0

typedef int Data;               

typedef struct Elem{
    Data data;
}elem;

typedef struct Pqueue{
    int numofelem;
    elem heap[LEN];
}pqueue;

void insert_max_heap(pqueue *h, Data item);
Data delete_max_heap(pqueue *h);
Data delete_max_heap2(pqueue *h);
int heapIsEmpty(pqueue* h);
void heapInit(pqueue* h);

#endif