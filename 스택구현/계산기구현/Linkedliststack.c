#include<stdio.h>
#include<stdlib.h>
#include"Linkedliststack.h"

void StackInit(Stack * stack){
    stack->head=malloc(sizeof(node));
    stack->head->next=NULL;
}

int SIsEmpty(Stack *stack){
    if(stack->head->next==NULL){
        return TRUE;
    }
    return FALSE;
}

void SPush(Stack *stack,Data data){
    node* newnode=malloc(sizeof(node));
    newnode->data=data;
    newnode->next=stack->head->next;
    stack->head->next=newnode;
}

Data SPop(Stack *stack){
    if(SIsEmpty(stack)){
        return FALSE;
    }
    else{
        node* rnode=stack->head->next;
        Data rdata=rnode->data;
        stack->head->next=rnode->next;
        free(rnode);
        return rdata;
    }
}

Data SPeek(Stack *stack){
    if(SIsEmpty(stack)){
        return FALSE;
    }
    return stack->head->next->data;
}