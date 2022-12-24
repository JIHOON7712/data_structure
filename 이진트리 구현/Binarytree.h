#ifndef __BINARY_TREE__
#define __BINARY_TREE__

typedef int Data;

typedef struct BNode{
    Data data;
    struct BNode* left;
    struct BNode* right;
}bnode;

bnode* Makenode(void);
Data Getdata(bnode* bt);
void Setdata(bnode* bt,Data data);

bnode* Getleftsub(bnode* bt);
bnode* Getrightsub(bnode* bt);

void Makeleftsubtree(bnode* main,bnode* sub);
void Makerightsubtree(bnode* main,bnode* sub);

void removetree(bnode* bt);
void display(bnode* bt);

bnode* searchTree(bnode* bt,Data data);
#endif