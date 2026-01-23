#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2){

		printf("ERROR: You need only one argument. \n");
		return 1;
	}

	int i = 0;
	for(i = 0; argv[1][i] != '\0' ; i++){
		char letter = argv[1][i];

		switch (letter){
			case 'a':
			case 'A':
				printf("%d: 'A'\n", (int) 'a' );
				break;

			case 'e':
			case 'E':
				printf("%d: 'E'\n",(int) 'e');
				break;

			case 'i':
			case 'I':
				printf("%d: 'I'\n",(int) 'i');
				break;

			case 'o':
			case 'O':
				printf("%d: 'O'\n",(int) 'o');
				break;

			case 'u':
			case 'U':
				printf("%d: 'A'\n",(int) 'u');
				break;

			case 'y':
			case 'Y':
				
				if (i>2){
					printf("%d: 'Y'\n",i);
				}
				break;

			default:
				printf("%d: %c is not a vowel \n",i,letter);

		}
	}
}