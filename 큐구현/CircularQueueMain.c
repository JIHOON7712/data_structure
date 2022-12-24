#include <stdio.h>
#include "ArrayBasequeue.h"

int main(void)
{
	// Queue의 생성 및 초기화 ///////
	queue q;
	QueueInit(&q);

	// 데이터 넣기 ///////
	enQueue(&q, 1);  enQueue(&q, 2);
	enQueue(&q, 3);  enQueue(&q, 4);
	enQueue(&q, 5);

	// 데이터 꺼내기 ///////
	while(!QIsEmpty(&q))
		printf("%d ", deQueue(&q)); 

	return 0;
}