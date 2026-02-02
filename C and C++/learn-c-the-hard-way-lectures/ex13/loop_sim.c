#include <stdio.h>

int main( int argc , char *argv[])
{
	char steps[] = {'L', 'O', 'O', 'P', '\0'};

	char node = steps[0];
	int i = 0;

	// Increment
	ankara:
	node = steps[i];

	// Jumper
	if (node != '\0'){
		printf("%c",node);
		i += 1;
		goto ankara;
	} 

	printf("\n");

	return 0;

}