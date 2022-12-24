#include<stdio.h>
#include<stdlib.h>
#include"Members.h"

//컴파일 명령어: cd "d:\열혈 자료구조\원형연결리스트\5-1\" && gcc Members.c Membermain.c -o Membermain && "d:\열혈 자료구조\원형연결리스트\5-1\"Membermain

int main(void){
    List list;
    CData data;
    CListInit(&list);

    //5명의 사원정보 입력
    char* name=(char*)malloc(sizeof(char)*15);
    int idnum;
    for(int i=0;i<5;i++){
        printf("%d번째 사원의 이름을 입력하시오 :",i+1);
        scanf("%s",name);
        getchar();
        printf("%d번째 사원의 사원번호를 입력하시오 :",i+1);
        scanf("%d",&idnum);
        getchar();
        CInsert(&list,MakeMembers(name,idnum));
    }

    //모든 사원정보를 출력
    if(CFirst(&list,&data)){
        printf("이름 :%s\n사원번호 :%d\n",data->name,data->idnum);
        for(int j=0;j<list.numOfData-1;j++){
            CNext(&list,&data);
            printf("이름 :%s\n사원번호 :%d\n",data->name,data->idnum);
        }
    }

    //1명의 정보를 삭제
    CRemove(&list);
    
    //삭제 후 사원정보를 출력
    if(CFirst(&list,&data)){
        printf("이름 :%s\n사원번호 :%d\n",data->name,data->idnum);
        for(int j=0;j<list.numOfData;j++){
            CNext(&list,&data);
            printf("이름 :%s\n사원번호 :%d\n",data->name,data->idnum);
        }
    }

    //당직 찾기
    printf("당신의 이름을 입력하시오. :");
    scanf("%s",name);
    getchar();
    printf("몇일 후의 당직사원을 알고싶으신가요? :");
    scanf("%d",&idnum);
    getchar();
    printf("%d날 이후의 당직은 : %s",idnum,dutyCount(&list,name,idnum));
}