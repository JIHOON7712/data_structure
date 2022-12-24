#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

void ListInit(List * plist){
    plist->head=(node*)malloc(sizeof(node));
    plist->head->next=NULL;
    plist->cur=plist->head;
    plist->before=plist->head;
    plist->size=0;
}

void LInsert(List * plist, Data data){
    node* nnode=(node*)malloc(sizeof(node));
    nnode->data=data;
    nnode->next=plist->head;
    plist->head=nnode;
    (plist->size)++;
}
Data LRemove(List * plist){
    if(plist->head->next == NULL)
		return FALSE;
    node* rnode=plist->cur;
    Data rdata=rnode->data;

    plist->before->next=plist->cur;
    plist->cur=plist->before;
    free(rnode);
    (plist->size)--;
    return rdata;
}

int LFirst(List * plist, Data * pdata){
    if(plist->head->next == NULL)
		return FALSE;

    plist->cur=plist->head->next;
    *pdata=plist->cur->data;
    return TRUE;
}
int LNext(List * plist, Data * pdata){
    if(plist->head->next == NULL)
		return FALSE;
    plist->before=plist->cur;
    plist->cur=plist->cur;

    *pdata= plist->cur->data;
    return TRUE;
}


int LCount(List * plist){
    return plist->size;
}

void GraphInit(graph* gh){
  gh->numE=0;
  gh->numV=0;
  gh->adjacent=NULL;
}
void insert_vertex(graph* gh,int v){
  List* nlist=(List*)malloc(sizeof(List));
  Listinit(nlist);
  LInsert(nlist,v);
  
}
void insert_edge(graph* gh, int from,int to);

void delete_vertex(graph* gh,int v);
void delete_edge(graph* gh, int from,int to);

int is_empty(graph* gh);
void destroy_graph(graph* gh);