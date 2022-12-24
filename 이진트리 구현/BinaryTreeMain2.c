#include <stdio.h>
#include "Binarytree.h"

void ShowIntData(int data);

int main(void)
{
	bnode * bt1 = Makenode();
	bnode * bt2 = Makenode();
	bnode * bt3 = Makenode();
	bnode * bt4 = Makenode();
	bnode * bt5 = Makenode();
	bnode * bt6 = Makenode();

	Setdata(bt1, 1);
	Setdata(bt2, 2);
	Setdata(bt3, 3);
	Setdata(bt4, 4);
	Setdata(bt5, 5);
	Setdata(bt6, 6);

	Makeleftsubtree(bt1, bt2);
	Makerightsubtree(bt1, bt3);
	Makeleftsubtree(bt2, bt4);
	Makerightsubtree(bt2, bt5);
	Makerightsubtree(bt3, bt6);

	display(bt1);
	return 0;
}
