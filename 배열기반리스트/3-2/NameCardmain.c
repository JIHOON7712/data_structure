#include<stdio.h>
#include<stdlib.h>
#include"Arraylist.h"

int main(void){
    List list;
    LData data;
    char* sear=malloc(sizeof(char)*15);
    ListInit(&list);

    for(int i=0;i<5;i++){       //세 사람의 정보를 입력
        char* name=malloc(sizeof(char)*15);
        char* phone=malloc(sizeof(char)*15);
        printf("이름을 입력하시오 :");
        scanf("%s",name);
        getchar();
        printf("번호을 입력하시오 :");
        scanf("%s",phone);
        getchar();
        LData new=MakeNameCard(name,phone);
        free(name);
        free(phone);
        LInsert(&list,new);
    }

    printf("검색할 이름을 입력하시오: ");
    scanf("%s",sear);
    getchar();
    if(LFirst(&list,&data)){
        if(NameCompare(data,sear)==0){
            ShowNameCardInfo(data);
        }
        while(LNext(&list,&data)){
            if(NameCompare(data,sear)==0){
                ShowNameCardInfo(data);
            }
        }
    }

    printf("삭제할 이름을 입력하시오: ");
    scanf("%s",sear);
    getchar();
    if(LFirst(&list,&data)){
        if(NameCompare(data,sear)==0){
            LRemove(&list);
        }
        while(LNext(&list,&data)){
            if(NameCompare(data,sear)==0){
                LRemove(&list);
            }
        }
    }
    
    if(LFirst(&list,&data)){
        ShowNameCardInfo(data);
        while(LNext(&list,&data)){
            ShowNameCardInfo(data);
        }
    }
}