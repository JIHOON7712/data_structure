#include <stdio.h>
#include "ArrayBasequeue.h"

int main(void)
{
	// Queue�� ���� �� �ʱ�ȭ ///////
	queue q;
	QueueInit(&q);

	// ������ �ֱ� ///////
	enQueue(&q, 1);  enQueue(&q, 2);
	enQueue(&q, 3);  enQueue(&q, 4);
	enQueue(&q, 5);

	// ������ ������ ///////
	while(!QIsEmpty(&q))
		printf("%d ", deQueue(&q)); 

	return 0;
}