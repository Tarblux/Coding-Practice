#include <stdio.h>

static void arithmeticOperators()
{	
	printf("arithmetic: \n");

	int value = 0;
	// value = value + 1;
	value += 8; 
	value %= 3; 

	printf("%d \n",value);
}

static void bitwiseOperators()
{
	printf("bitwise: \n");
	int bits = 1;

}

static void relationalOperators()
{
	printf("relational: \n");
	int val = 3;
}

static void logicalOperators()
{
	printf("logical: \n");
	int logi = 4;
}

int main()
{
	arithmeticOperators();
	bitwiseOperators();
	relationalOperators();
	logicalOperators();
	return 0;
}
