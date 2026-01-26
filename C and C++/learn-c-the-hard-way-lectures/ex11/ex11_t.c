#include <stdio.h>

int main(int argc, char *argv[]){

	int numbers[4] = { 0 };
	char name[6] = { 'a' };

	// Print all numbers
	printf("numbers: %d %d %d %d \n", numbers[0], numbers[1], numbers[2], numbers[3]);

	// Print all chars in name
	printf("name each : %c %c %c %c %c \n", name[0], name[1], name[2], name[3], name[4]);

	printf("name: %s \n", name);

	// setup the numbers
	
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4; 

	// setup the name

	name[0] = 'T';
	name[1] = 'A';
	name[2] = 'R';
	name[3] = 'I';
	name[4] = 'Q';

	// Print all numbers (after intialization)
	printf("numbers: %d %d %d %d \n", numbers[0], numbers[1], numbers[2], numbers[3]);

	// Print all chars in name (after intialization)
	printf("name: %c %c %c %c %c \n", name[0], name[1], name[2], name[3], name[4]);

	printf("name: %s \n", name);

	// another way to use name 
	char *another = "lex";

	printf("another: %s \n" , another);

	// Print all chars in another
	printf("another: %c %c %c %c \n", another[0], another[1], another[2], another[3]);

	return 0;
}