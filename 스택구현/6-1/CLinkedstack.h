#ifndef __CLINKED_BASED_STACK
#define __CLINKED_BASED_STACK

#include"CLinkedList.h"

void StackInit(CList *);
int SIsEmpty(CList *);
void SPush(CList *,Data);
Data SPop(CList *);
Data SPeek(CList *);

#endif