#include <stdio.h>
#include <stdlib.h>
#include "Binarysearchtree.h"
#include"Binarytree.h"

int main(void)
{
	bnode* bstRoot;
	bnode* sNode;    // search node

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 4);
	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 7);
	
	display(bstRoot); 
	printf("\n");
	sNode = BSTRemove(&bstRoot, 3);
	free(sNode);

	display(bstRoot);
	printf("\n");
	sNode = BSTRemove(&bstRoot, 8);
	free(sNode);

	display(bstRoot); 
	printf("\n");
	sNode = BSTRemove(&bstRoot, 1);
	free(sNode);

	display(bstRoot);
	printf("\n");
	sNode = BSTRemove(&bstRoot, 6);
	free(sNode);

	display(bstRoot);
	printf("\n");
	return 0;
}