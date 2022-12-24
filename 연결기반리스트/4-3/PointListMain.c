#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int compare(LData inp,LData next){
	if(PointComp(inp,next)==0){
		return 0;
	}
	else if(PointComp(inp,next)==1){
		if((inp->ypos)>(next->ypos)){
			return 0;
		}
		else{
			return 1;
		}
	}
	else{
		if(inp->xpos > next->xpos){
			return 0;
		}
		else return 1;
	}
}

int main(void)
{
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);
	SetSortRule(&list,compare);

	// 4���� ������ ����  ///////////
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	// ����� �������� ��� ///////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	// xpos�� 2�� ��� ������ ����  ///////////
	compPos.xpos=2;
	compPos.ypos=0;

	if(LFirst(&list, &ppos))
	{
		if(PointComp(ppos, &compPos)==1)
		{
			ppos=LRemove(&list);
			free(ppos);
		}
		
		while(LNext(&list, &ppos)) 
		{
			if(PointComp(ppos, &compPos)==1)
			{
				ppos=LRemove(&list);
				free(ppos);
			}
		}
	}

	// ���� �� ���� ������ ��ü ���  ///////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}