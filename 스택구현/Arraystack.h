#ifndef __ARRAY_BASED_STACK__
#define __ARRAY_BASED_STACK__

#define TRUE 1
#define FALSE 0

#define Arraysize 100
typedef int Data;

typedef struct ARRAYLIST{
    Data array[Arraysize];
    int top;
}list;

void StackInit(list *);
int SIsEmpty(list *);
void SPush(list *,Data);
Data SPop(list *);
Data SPeek(list *);
#endif