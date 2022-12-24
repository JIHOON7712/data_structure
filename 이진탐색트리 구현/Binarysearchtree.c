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

    while(cnode!=NULL){ //���� ���� ����� �ڸ��� ã�ư��� ����
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

    nnode=(bnode*)malloc(sizeof(bnode));    //���ο� ��� ����
    nnode->left=NULL;
    nnode->right=NULL;
    nnode->data=data;

    if(pnode!=NULL){    //���ο� ��� ����
        if((pnode->data)>data){
            pnode->left=nnode;
        }
        else{
            pnode->right=nnode;
        }
    }
    else{   //����Ʈ���� ��尡 �Ѱ��� ���
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
    froot->right=*proot;    //������ ��� ����
    bnode* pnode=froot;
    bnode* cnode=*proot;
    bnode* rnode;
    bnode* dnode;

    while(cnode!=NULL && cnode->data!=target){  //������ ��Ʈ�� ��ġ�� �˻�
        pnode=cnode;
        if(cnode->data>target){
            cnode=cnode->left;
        }
        else{
            cnode=cnode->right;
        }
    }

    if(cnode==NULL){    //Ÿ���� �߰����� ���� ���
        return NULL;
    }
    rnode=cnode;

    if(rnode->left==NULL && rnode->right==NULL){    //�ܸ� ����� ���
        if(pnode->left==rnode){
            pnode->left=NULL;
        }
        else{
            pnode->right=NULL;
        }
        dnode=rnode;
    }
    else if(rnode->left==NULL || rnode->right==NULL){   //�ڽ� ��尡 �� ���� ���
        bnode* rcnode;
        if(rnode->left==NULL){
            rcnode=rnode->right;
        }
        else{
            rcnode=rnode->left;
        }   //������� ����� �ڽĳ�带 ����ϱ�
        if(pnode->left==rnode){
            pnode->left=rcnode;
        }
        else{
            pnode->right=rcnode;
        }
        dnode=rnode;
    }
    else{   //�ڽĳ�尡 2���� ���
        bnode* mnode=rnode->right;  
        bnode* mpnode=rnode;
        int backup;
        while(mnode->left!=NULL){   //������� ���� ���� ����� �� �˻�
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

    if(froot->right!=*proot){   //�� ��� �ִ� ���
        *proot=froot->right;
    }
    free(froot);
    
    return dnode;
}