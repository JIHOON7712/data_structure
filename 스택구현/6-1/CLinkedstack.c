#include<stdio.h>
#include"CLinkedstack.h"
#include"CLinkedList.h"

void StackInit(CList *clist){
    ListInit(clist);
}

int SIsEmpty(CList *clist){
    if(LCount(clist)==0){
        return TRUE;
    }
    return FALSE;
}
void SPush(CList *clist,Data data){
    LInsertFront(clist,data);
}

Data SPop(CList *clist){
    Data rdata;
    if(LFirst(clist,&rdata)){
        rdata=LRemove(clist);
        return rdata;
    }
    return FALSE;
}

Data SPeek(CList * clist){
    return clist->tail->data;
}