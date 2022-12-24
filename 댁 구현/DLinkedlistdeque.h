#ifndef __DLINKED_BASE_DEQUE__
#define __DLINKED_BASE_DEQUE__

typedef int Data;

#define TRUE 1
#define FALSE 0

typedef struct Node{
    Data data;
    struct Node* next;
    struct Node* prev;
}node;

typedef struct Deque{
    node* head;
    node* tail;
}deque;

void DequeInit(deque * pdeq);
int DQIsEmpty(deque * pdeq);

void DQAddFirst(deque * pdeq, Data data);
void DQAddLast(deque * pdeq, Data data);

Data DQRemoveFirst(deque * pdeq);
Data DQRemoveLast(deque * pdeq);

Data DQGetFirst(deque * pdeq);
Data DQGetLast(deque * pdeq);
#endif