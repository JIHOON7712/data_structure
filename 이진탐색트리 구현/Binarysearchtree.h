#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

#include"Binarytree.h"

void BSTMakeAndInit(bnode ** proot);
Data BSTGetNodeData(bnode* bst);
void BSTInsert(bnode** proot,Data data);
bnode* BSTSearch(bnode* bst,Data target);

#endif