#include<stdio.h>
#include<stdlib.h>
#include"DLinkedlistdeque.h"

void DequeInit(deque * deq){
    deq->head=(node*)malloc(sizeof(node));
    deq->tail=(node*)malloc(sizeof(node));
    deq->head->next=deq->tail;
    deq->head->prev=NULL;
    deq->tail->next=NULL;
    deq->tail->prev=deq->head;
}

int DQIsEmpty(deque * deq){
    if(deq->head->next==deq->tail){
        return TRUE;
    }
    return FALSE;
}

void DQAddFirst(deque * deq, Data data){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->next=deq->head->next;
    newnode->prev=deq->head;
    deq->head->next->prev=newnode;
    deq->head->next=newnode;
    newnode->data=data;
}

void DQAddLast(deque * deq, Data data){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->next=deq->tail;
    newnode->prev=deq->tail->prev;
    deq->tail->prev->next=newnode;
    deq->tail->prev=newnode;
    newnode->data=data;
}

Data DQRemoveFirst(deque * deq){
    node* rnode=deq->head->next;
    Data rdata=rnode->data;
    deq->head->next=rnode->next;
    rnode->next->prev=deq->head;
    free(rnode);
    return rdata;
}

Data DQRemoveLast(deque * deq){
    node* rnode=deq->tail->prev;
    Data rdata=rnode->data;
    deq->tail->prev=rnode->prev;
    rnode->prev->next=deq->tail;
    free(rnode);
    return rdata;
}

Data DQGetFirst(deque * deq){
    return deq->head->next->data;
}

Data DQGetLast(deque * deq){
    return deq->tail->prev->data;
}