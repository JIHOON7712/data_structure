#include<stdio.h>
#include<stdlib.h>
#include"BLinkedlist.h"

void ListInit (List* plist){
    plist->head=(Node*)malloc(sizeof(Node));
    plist->tail=(Node*)malloc(sizeof(Node));
    plist->head->prev=NULL;
    plist->head->next=plist->tail;
    plist->tail->next=NULL;
    plist->tail->prev=plist->head;
    plist->numOfData=0; 
}

void LInsert(List* plist, Data data){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;

    newnode->prev=plist->tail->prev;
    newnode->next=plist->tail;

    plist->tail->prev=newnode;
    newnode->prev->next=newnode;
    (plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata){
    if(plist->head->next==plist->tail){
        return FALSE;
    }
    plist->cur=plist->head->next;
    *pdata=plist->cur->data;
    return TRUE;
}

int LNext(List* plist,Data* pdata){
    if(plist->cur->next == plist->tail){
        return FALSE;
    }
    else{
        plist->cur=plist->cur->next;
        *pdata=plist->cur->data;
        return TRUE;
    }
}

int LPrevious(List* plist,Data* pdata){
    if(plist->cur->prev==plist->head){
        return FALSE;
    }
    else{
        plist->cur=plist->cur->prev;
        *pdata=plist->cur->data;
        return TRUE;
    }
}

Data LRemove(List* plist){
    Node* rpos=plist->cur;
    Data rdata=rpos->data;

    plist->cur=plist->cur->prev;
    plist->cur->next=rpos->next;
    rpos->next->prev=rpos->prev;

    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List* plist){
    return plist->numOfData;
}