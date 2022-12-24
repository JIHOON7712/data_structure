#ifndef __ARRAY_BASE__QUEUE__
#define __ARRAY_BASE_QUEUE__

#define max_len 100
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct Queue{
    Data* front;
    Data* rear;
    int arr[max_len];
}queue;

void QueueInit(queue*);
int QIsEmpty(queue*);
void enQueue(queue*,Data);
Data deQueue(queue*);
Data QPeek(queue*);

#endif