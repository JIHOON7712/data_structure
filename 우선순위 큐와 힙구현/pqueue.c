#include <stdio.h>
#include <stdlib.h>
#include"pqueue.h"

int heapIsEmpty(pqueue* h){
    if(h->numofelem==0){
        return TRUE;
    }
    return FALSE;
}

void heapInit(pqueue* h){
    h->numofelem=0;
}

void insert_max_heap(pqueue *h, Data item){
    int i;
    i = ++(h->numofelem);
    while((i!=1)&&(item > h->heap[i/2].data)){
        h->heap[i].data = h->heap[i/2].data;
        i /= 2;
    }
    h->heap[i].data = item;
}

Data delete_max_heap(pqueue *h){
    int parent, child;
    Data rdata,item;
    rdata = h->heap[1].data;
    item = h->heap[(h->numofelem)--].data;
    h->heap[1].data=item;
    parent = 1;
    child=2;
    while(child <= h->numofelem){
        if((child < h->numofelem) && (h->heap[child].data) < h->heap[child+1].data)
            child++;
        if(item >= h->heap[child].data) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *=2;
    }
    h->heap[parent].data = item;
    return rdata;
}

Data delete_max_heap2(pqueue *h){
    int parent, child;
    parent=1;
    Data rdata,item;
    rdata = h->heap[1].data;
    item = h->heap[(h->numofelem)--].data;
    h->heap[1].data=item;
    while(parent*2 <= (h->numofelem)){
        if((h->heap[parent*2].data) < h->heap[parent*2+1].data){
            child=parent*2+1;
        }
        else child=parent*2;
        if(item >= h->heap[child].data) break;
        h->heap[parent] = h->heap[child];
        parent = child;
    }
    h->heap[parent].data = item;
    return rdata;
}