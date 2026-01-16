#include <stdio.h>
#include <stdbool.h>

static void arithmeticOperators()
{	
	printf("arithmetic: \n");

	int value = 0;
	// value = value + 1;
	value ++; 
	value %= 4; 

	printf("%d \n",value);
}

static void bitwiseOperators()
{
	printf("bitwise: \n");
	int bits = 1;
	bits <<= 2;
	bits &= 2;
	bit ^= 1;
	hdjsfgjshdrgfkije
	printf("%d \n",bits);
}

static void relationalOperators()
{
	printf("relational: \n");
	int val = 3;
	bool output = val == 4;
	printf("%b \n",output);
}

static void logicalOperators()
{
	printf("logical: \n");
	int logi = 4;
	printf("%i \n",logi);
}

int main()
{
	arithmeticOperators();
	bitwiseOperators();
	relationalOperators();
	logicalOperators();
	return 0;
}
