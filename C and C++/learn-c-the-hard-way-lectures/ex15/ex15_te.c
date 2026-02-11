#include <stdio.h>

int main(int argc, char *argv[]){

	char name[5] = {'T', 'A', 'R', 'I', 'Q'};
	char letter = name[0];
	// char *letter_2 = &name[1];

	char *letter_p = name;
	char *p2 = letter_p;

	char *address = &letter;

	printf("%p is the first letter's pointer \n", letter_p);
	printf("%p is the first letter's address \n", &letter);
	printf("%c is the char at the adresss \n" , *address);
	printf("%p is the pointer for pointer of letter_p \n" , p2);

}