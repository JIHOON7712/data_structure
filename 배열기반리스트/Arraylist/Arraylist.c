#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist){        //리스트의 주소값을 받아 초기화 하는 함수
    (plist->numOfData) = 0;
	(plist->curPosition) = 0;
}

void LInsert(List * plist, LData data){     //입력된 data를 리스트에 넣는 함수
    if((plist->numOfData)>LIST_LEN){        //배열이 다 차면 그만
        printf("저장이 불가능합니다\n");
        return;
    }
    plist->arr[plist->numOfData]=data;
    (plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata){        //pdata에 리스트의 첫 번째 값을 저장하고 T/F를 반환하는 함수
    if(plist->numOfData == 0){      //배열이 비어있으면 FALSE
		return FALSE;
    }
    plist->curPosition=0;
    *pdata=plist->arr[0];
    return TRUE;      
}

int LNext(List * plist, LData * pdata){     //마지막 반환 데이터의 다음 데이터를 반환
    if(plist->curPosition >= (plist->numOfData)-1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist){        //리스트의 마지막 반환 데이터를 삭제
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