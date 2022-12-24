#include<stdio.h>
#include<stdlib.h>
#include"Binarysearchtree.h"

void BSTMakeAndInit(bnode ** proot){
    *proot=NULL;
}

Data BSTGetNodeData(bnode* bst){
    return Getdata(bst);
}

void BSTInsert(bnode** proot,Data data){
    bnode* pnode=NULL;
    bnode* cnode=*proot;
    bnode* nnode=NULL;

    while(cnode!=NULL){ //새로 만들 노드의 자리를 찾아가는 과정
        if((cnode->data)==data){
            return;
        }
        pnode=cnode;
        if((cnode->data) > data){
            cnode=cnode->left;
        }
        else{
            cnode=cnode->right;
        }
    }

    nnode=(bnode*)malloc(sizeof(bnode));    //새로운 노드 생성
    nnode->left=NULL;
    nnode->right=NULL;
    nnode->data=data;

    if(pnode!=NULL){    //새로운 노드 삽입
        if((pnode->data)>data){
            pnode->left=nnode;
        }
        else{
            pnode->right=nnode;
        }
    }
    else{   //이진트리의 노드가 한개인 경우
        *proot=nnode;
    }
}

bnode* BSTSearch(bnode* bst,Data target){
    bnode* snode=bst;
    while(snode!=NULL){
        if((snode->data)==target){
            return snode;
        }
        if((snode->data) > target){
            snode=snode->left;
        }
        else{
            snode=snode->right;
        }
    }
    return NULL;
}

bnode* BSTRemove(bnode **proot,Data target){
    bnode* froot=(bnode*)malloc(sizeof(bnode));
    froot->right=*proot;    //가상의 노드 생성
    bnode* pnode=froot;
    bnode* cnode=*proot;
    bnode* rnode;
    bnode* dnode;

    while(cnode!=NULL && cnode->data!=target){  //삭제할 노트의 위치를 검색
        pnode=cnode;
        if(cnode->data>target){
            cnode=cnode->left;
        }
        else{
            cnode=cnode->right;
        }
    }

    if(cnode==NULL){    //타깃을 발견하지 못한 경우
        return NULL;
    }
    rnode=cnode;

    if(rnode->left==NULL && rnode->right==NULL){    //단말 노드인 경우
        if(pnode->left==rnode){
            pnode->left=NULL;
        }
        else{
            pnode->right=NULL;
        }
        dnode=rnode;
    }
    else if(rnode->left==NULL || rnode->right==NULL){   //자식 노드가 한 개인 경우
        bnode* rcnode;
        if(rnode->left==NULL){
            rcnode=rnode->right;
        }
        else{
            rcnode=rnode->left;
        }   //지우려는 노드의 자식노드를 백업하기
        if(pnode->left==rnode){
            pnode->left=rcnode;
        }
        else{
            pnode->right=rcnode;
        }
        dnode=rnode;
    }
    else{   //자식노드가 2개인 경우
        bnode* mnode=rnode->right;  
        bnode* mpnode=rnode;
        int backup;
        while(mnode->left!=NULL){   //지우려는 값과 제일 가까운 값 검색
            mpnode=mnode;
            mnode=mnode->left;
        }

        backup=rnode->data;
        rnode->data=mnode->data;

        if(mpnode->left==mnode){
            mpnode->left=mnode->right;
        }
        else{
            mpnode->right=mnode->right;
        }
        dnode=mnode;
        dnode->data=backup;
    }

    if(froot->right!=*proot){   //텅 비어 있는 경우
        *proot=froot->right;
    }
    free(froot);
    
    return dnode;
}