#include<stdio.h>
#include<stdlib.h>
#include"ArrayBasequeue.h"

void QueueInit(queue* que){
    que->front=que->arr;
    que->rear=que->arr;
}

int QIsEmpty(queue* que){
    if(que->front==que->rear){
        return TRUE;
    }
    return FALSE;
}

void enQueue(queue* que,Data data){
    if(que->rear==que->arr+(max_len-1)){
        if(que->front==que->arr){
            printf("FULL");
        }
        else{
            que->rear=que->arr+1;
            *(que->rear)=data;
        }
    }
    else{
        que->rear=que->rear+1;
        *(que->rear)=data;
    }
}

Data deQueue(queue* que){
    int rdata;
    que->front=que->front+1;
    rdata=*(que->front);
    return rdata;
}

Data QPeek(queue* que){
    int rdata;
    if(que->front==que->arr){
        que->front=que->front+1;
        rdata=*(que->front);
    }
    else{
        rdata=*(que->front);
    }
    return rdata;
}