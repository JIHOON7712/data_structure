#include<stdio.h>
#include<stdlib.h>
#include"Members.h"

//������ ��ɾ�: cd "d:\���� �ڷᱸ��\�������Ḯ��Ʈ\5-1\" && gcc Members.c Membermain.c -o Membermain && "d:\���� �ڷᱸ��\�������Ḯ��Ʈ\5-1\"Membermain

int main(void){
    List list;
    CData data;
    CListInit(&list);

    //5���� ������� �Է�
    char* name=(char*)malloc(sizeof(char)*15);
    int idnum;
    for(int i=0;i<5;i++){
        printf("%d��° ����� �̸��� �Է��Ͻÿ� :",i+1);
        scanf("%s",name);
        getchar();
        printf("%d��° ����� �����ȣ�� �Է��Ͻÿ� :",i+1);
        scanf("%d",&idnum);
        getchar();
        CInsert(&list,MakeMembers(name,idnum));
    }

    //��� ��������� ���
    if(CFirst(&list,&data)){
        printf("�̸� :%s\n�����ȣ :%d\n",data->name,data->idnum);
        for(int j=0;j<list.numOfData-1;j++){
            CNext(&list,&data);
            printf("�̸� :%s\n�����ȣ :%d\n",data->name,data->idnum);
        }
    }

    //1���� ������ ����
    CRemove(&list);
    
    //���� �� ��������� ���
    if(CFirst(&list,&data)){
        printf("�̸� :%s\n�����ȣ :%d\n",data->name,data->idnum);
        for(int j=0;j<list.numOfData;j++){
            CNext(&list,&data);
            printf("�̸� :%s\n�����ȣ :%d\n",data->name,data->idnum);
        }
    }

    //���� ã��
    printf("����� �̸��� �Է��Ͻÿ�. :");
    scanf("%s",name);
    getchar();
    printf("���� ���� ��������� �˰�����Ű���? :");
    scanf("%d",&idnum);
    getchar();
    printf("%d�� ������ ������ : %s",idnum,dutyCount(&list,name,idnum));
}