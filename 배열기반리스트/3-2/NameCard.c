#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Arraylist.h"

// NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
NameCard * MakeNameCard(char * name, char * phone){
    NameCard* newnode=(NameCard*)malloc(sizeof(NameCard));
    strcpy(newnode->name,name);
    strcpy(newnode->phone,phone);
    return newnode;
}

void ShowNameCardInfo(NameCard * pcard){
    printf("NAME : %s\n",pcard->name);
    printf("PHONE NUMBER : %s\n",pcard->phone);
}

int NameCompare(NameCard * pcard, char * name){
    if(strcmp(pcard->name,name)==0){
        return 0;
    }
    else
    {
        return 1;
    }
}

void ChangePhoneNum(NameCard * pcard, char * phone){
    strcpy(pcard->phone,phone);
}

