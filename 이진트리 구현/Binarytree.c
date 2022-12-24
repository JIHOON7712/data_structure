#include<stdio.h>
#include<stdlib.h>
#include"Binarytree.h"

bnode* Makenode(void){
    bnode* newnode=(bnode*)malloc(sizeof(bnode));
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

Data Getdata(bnode* bt){
    return bt->data;
}

void Setdata(bnode* bt,Data data){
    bt->data=data;
}

bnode* Getleftsub(bnode* bt){
    return bt->left;
}

bnode* Getrightsub(bnode* bt){
    return bt->right;
}

void Makeleftsubtree(bnode* main,bnode* sub){
    if(main->left!=NULL){
        removetree(main->left);
    }
    main->left=sub;
}
void Makerightsubtree(bnode* main,bnode* sub){
    if(main->right!=NULL){
        removetree(main->right);
    }
    main->right=sub;
}

void removetree(bnode* bt){
    if(bt==NULL){
        return ;
    }
    removetree(bt->left);
    removetree(bt->right);
    free(bt);
}

void display(bnode* bt){
    if(bt==NULL){
        return ;
    }
    display(bt->left);
    printf("%d\n",Getdata(bt));
    display(bt->right);
}