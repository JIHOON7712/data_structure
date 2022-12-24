#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist){
    plist->head=(Node*)malloc(sizeof(Node));
    plist->head->next=0;
    plist->numOfData=0;
    plist->comp = NULL;
    plist->tail=plist->head;
}

void LInsert(List* plist, LData data){
    if(plist->comp==NULL){
        FInsert(plist,data);
    }
    else{
        SInsert(plist,data);
    }
}

void FInsert(List* plist, LData data){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=0;

    plist->tail->next=newnode;
    plist->tail=newnode;

    (plist->numOfData)++;
}

void SInsert(List* plist, LData data){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=0;

    Node* pred=plist->head;
    while(pred->next !=0 && plist->comp(data,pred->next->data != 0)){
        pred=pred->next;
    }
    newnode->next=pred->next;
    pred->next=newnode;
    (plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata){
    if(plist->head->next==0){
        return FALSE;
    }
    plist->before=plist->head;
    plist->cur=plist->head->next;

    *pdata=plist->cur->data;
    return TRUE;
}

int LNext(List * plist, LData * pdata){
    if(plist->cur->next==0){
        return FALSE;
    }
    plist->before=plist->cur;
    plist->cur=plist->cur->next;
    *pdata=plist->cur->data;
    return TRUE;
}

LData LRemove(List * plist){
    Node* rpos;
    LData rdata;
    rpos=plist->cur;
    rdata=plist->cur->data;
    plist->before->next=plist->cur->next;
    plist->cur=plist->before;
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List * plist){
    return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2)){
    plist->comp=comp;
}