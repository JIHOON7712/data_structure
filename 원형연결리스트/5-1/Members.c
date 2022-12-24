#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Members.h"

char* dutyCount(List* plist,char* find,int nextday){
    Node* search=plist->tail->next;
    int i=0;
    while(i<plist->numOfData){
        if(strcmp(search->data->name,find)==0){
            for(int j=0;j<nextday;j++){
                search=search->next;
            }
            return search->data->name;
        }
        search=search->next;
        i++;
    }
    return "NOT FOUND";
}

Member* MakeMembers(char* name,int idnum){
    Member* newmem=(Member*)malloc(sizeof(Member));
    newmem->idnum=idnum;
    strcpy(newmem->name,name);
    return newmem;
}

void CListInit(List * plist){
    plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void CInsert(List * plist, CData data){
    if(plist->tail==NULL){
        Node* newnode=(Node*)malloc(sizeof(Node));
        newnode->data=data;
        plist->tail=newnode;
        plist->tail->next=newnode;
        (plist->numOfData)++;
    }
    else{
        Node* newnode=(Node*)malloc(sizeof(Node));
        newnode->data=data;
        newnode->next=plist->tail->next;
        plist->tail->next=newnode;
        plist->tail=newnode;
        (plist->numOfData)++;
    }
}


int CFirst(List * plist, CData * pdata){
    if(plist->tail==NULL){
        return FALSE;
    }
    else{
        *pdata=plist->tail->data;
        plist->cur=plist->tail;
        return TRUE;
    }
}

void CNext(List * plist, CData * pdata){
    *pdata=plist->cur->next->data;
    plist->before=plist->cur;
    plist->cur=plist->cur->next;
}

CData CRemove(List * plist){
    CData pdata=plist->cur->data;
    Node* rpos=plist->cur;
    if(plist->cur==plist->tail){
        if(plist->cur->next==plist->tail){
            plist->tail=NULL;
            free(rpos);
            (plist->numOfData)--;
            return pdata;
        }
        else{
            plist->tail=plist->before;
            free(rpos);
            (plist->numOfData)--;
            return pdata;
        }
    }
    plist->cur=plist->before;
    plist->before->next=rpos->next;
    free(rpos);
    (plist->numOfData)--;
    return pdata;
}

int CCount(List * plist){
    return plist->numOfData;
}