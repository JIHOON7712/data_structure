#include <stdio.h>
#include "calcul.h"

//cd "d:\열혈 자료구조\스택구현\계산기구현\" && gcc InfixCalculatorMain.c calcul.c Postfix.c Linkedliststack.c -o InfixCalculatorMain && "d:\열혈 자료구조\스택구현\계산기구현\"InfixCalculatorMain

int main(void)
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	printf("%s = %d \n", exp1, calCul(exp1));
	printf("%s = %d \n", exp2, calCul(exp2));
	printf("%s = %d \n", exp3, calCul(exp3));
	return 0;
}