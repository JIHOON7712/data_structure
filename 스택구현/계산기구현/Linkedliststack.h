#ifndef __LINKED_BASED_STACK__
#define __LINKED_BASED_STACK__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct Node{
    Data data;
    struct Node* next;
}node;

typedef struct LIST{
    node* head;
}Stack;

void StackInit(Stack *);
int SIsEmpty(Stack *);
void SPush(Stack *,Data);
Data SPop(Stack *);
Data SPeek(Stack *);

#endif