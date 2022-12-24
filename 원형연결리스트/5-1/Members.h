#ifndef __MEMBER_H
#define __MEMBER_H

#define TRUE 1
#define FALSE 0

typedef struct member{
    int idnum;
    char name[30];
}Member;

typedef Member* CData;

typedef struct node{
    CData data;
    struct node* next;
}Node;

typedef struct Clinkedlist{
    Node* tail;
    Node* before;
    Node* cur;
    int numOfData;
}CLinkedlist;

typedef CLinkedlist List;

char* dutyCount(List* plist,char* find,int nextday);

Member* MakeMembers(char* name,int idnum);

void CListInit(List * plist);
void CInsert(List * plist, CData data);


int CFirst(List * plist, CData * pdata);
void CNext(List * plist, CData * pdata);

CData CRemove(List * plist);
int CCount(List * plist);

#endif