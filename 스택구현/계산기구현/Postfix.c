#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "Postfix.h"
#include"Linkedliststack.h"

int Getopprio(char op){
    switch(op)
    {
        case '*': case '/':
            return 5;
        case '+': case '-':
            return 3;
        case '(':
            return 1;
    }
    return -1;
}

int Whoopprio(char op1,char op2){
    int prio1=Getopprio(op1);
    int prio2=Getopprio(op2);
    if(prio1>prio2){
        return 1;
    }
    else if(prio1<prio2){
        return -1;
    }
    else 
        return 0;
}

void Convtopostfix(char exp[]){
    int explen=strlen(exp);
    Stack operator;
    char *postfix=(char*)malloc(sizeof(char)*(explen+1));

    memset(postfix,0,sizeof(char)*explen+1);
    StackInit(&operator);
    int index=0;
    char text;

    for(int i=0;i<explen;i++){
        text=exp[i];
        if(isdigit(text)){
            postfix[index++]=text;
        }
        else{
            switch(text){
            case '(':
                SPush(&operator,text);
                break;
            case ')':
                while(SPeek(&operator)!='('){
                    postfix[index++]=SPop(&operator);
                }
                SPop(&operator);
                break;
            case '*': case '/':
            case '+': case '-':
                while(!SIsEmpty(&operator) && Whoopprio(SPeek(&operator),text) >=0)
                    postfix[index++]=SPop(&operator);
            
                SPush(&operator,text);
                break;
            }
        }
    }
    while(!SIsEmpty(&operator)){
        postfix[index++]=SPop(&operator);
    }
    strcpy(exp,postfix);
    free(postfix);
}
