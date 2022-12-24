#include<stdio.h>
#include"Arraystack.h"

void StackInit(list *plist){
    plist->top=-1;
}

int SIsEmpty(list *plist){
    if(plist->top==-1){
        return TRUE;
    }
    return FALSE;
}

void SPush(list *plist,Data data){
    plist->top++;
    plist->array[plist->top]=data;
}

Data SPop(list *plist){
    if(SIsEmpty(plist)){
        return;
    }
    Data rdata=plist->array[plist->top];
    plist->top--;
    return rdata;
}

Data SPeek(list *plist){
    if(SIsEmpty(plist)){
        return;
    }
    return plist->array[plist->top];
}