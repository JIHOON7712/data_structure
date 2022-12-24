#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"Linkedliststack.h"
#include"Postfix.h"

int calCul(char exp[]){
    Stack cal;
    StackInit(&cal);

    Convtopostfix(exp);

    int i=0;
    int result;
    int op1,op2;
    while(i<strlen(exp)){
        if(isdigit(exp[i])){
            SPush(&cal,exp[i]-'0');
        }
        else{
            op1=SPop(&cal);
            op2=SPop(&cal);

            switch(exp[i]){
                case '+' : 
                    result=op1+op2;
                    SPush(&cal,result);
                    break;
                case '-' : 
                    result=op2-op1;
                    SPush(&cal,result);
                    break;
                case '*' : 
                    result=op1*op2;
                    SPush(&cal,result);
                    break;
                case '/' :
                    result=op2/op1;
                    SPush(&cal,result);
                    break;
            }
        }
        i++;
    }
    return SPop(&cal);
}