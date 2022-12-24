#include<stdio.h>
#include"pqueue.h"

void display(pqueue* h){
    for(int i=1;i<= (h->numofelem);i++){
        printf("%d ",h->heap[i].data);
    }
    printf("\n");
}

int main(void){
    pqueue heap;
    heapInit(&heap);
    insert_max_heap(&heap,1);
    insert_max_heap(&heap,2);
    insert_max_heap(&heap,3);
    insert_max_heap(&heap,4);
    insert_max_heap(&heap,5);
    insert_max_heap(&heap,6);
    insert_max_heap(&heap,7);
    insert_max_heap(&heap,8);
    insert_max_heap(&heap,9);
    display(&heap);
    delete_max_heap2(&heap);
    display(&heap);
}
