#include <stdio.h>
#include "Postfix.h"

int main(void)
{
	char exp1[]= "1+2*3";
	char exp2[]= "(1+2)*3";
	char exp3[]= "((1-2)+3)*(5-2)";

	Convtopostfix(exp1);
	Convtopostfix(exp2);
	Convtopostfix(exp3);

	printf("%s \n", exp1);
	printf("%s \n", exp2);
	printf("%s \n", exp3);
	return 0;
}