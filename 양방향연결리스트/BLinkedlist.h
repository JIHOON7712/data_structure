#ifndef __DUBLYLINKED__H
#define __DUBLYLINKED__H

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node{
    Data data;
    struct node* next;
    struct node* prev;
}Node;

typedef struct dbDlinkedlist{
    Node* head;
    Node* tail;
    Node* cur;
    int numOfData;
}DBDlinkedlist;

typedef DBDlinkedlist List;

void ListInit (List* plist);
void LInsert(List* plist, Data data);

int LFirst(List* plist, Data* pdata);
int LNext(List* plist,Data* pdata);
int LPrevious(List* plist,Data* pdata);

Data LRemove(List* plist);
int LCount(List* plist);

#endif