#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist){        //����Ʈ�� �ּҰ��� �޾� �ʱ�ȭ �ϴ� �Լ�
    (plist->numOfData) = 0;
	(plist->curPosition) = 0;
}

void LInsert(List * plist, LData data){     //�Էµ� data�� ����Ʈ�� �ִ� �Լ�
    if((plist->numOfData)>LIST_LEN){        //�迭�� �� ���� �׸�
        printf("������ �Ұ����մϴ�\n");
        return;
    }
    plist->arr[plist->numOfData]=data;
    (plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata){        //pdata�� ����Ʈ�� ù ��° ���� �����ϰ� T/F�� ��ȯ�ϴ� �Լ�
    if(plist->numOfData == 0){      //�迭�� ��������� FALSE
		return FALSE;
    }
    plist->curPosition=0;
    *pdata=plist->arr[0];
    return TRUE;      
}

int LNext(List * plist, LData * pdata){     //������ ��ȯ �������� ���� �����͸� ��ȯ
    if(plist->curPosition >= (plist->numOfData)-1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist){        //����Ʈ�� ������ ��ȯ �����͸� ����
    int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for(i=rpos; i<num-1; i++)
		plist->arr[i] = plist->arr[i+1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List * plist){
    return plist->numOfData;
}