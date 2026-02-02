#include <stdio.h>
#include <ctype.h>

// forward declarations
int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[])
{
	int i = 0;

	for (i = 0 ; i < argc ; i++){

		char *cur_arg = argv[i];
		int j = 0;

		for (j = 0; cur_arg[j]  != '\0'; j++){
			char ch = cur_arg[j];

			if (isalpha((int)ch) || isblank((int)ch)){
				printf("'%c' == %d \n",ch,ch);
			}
		}
	}
}

// void print_letters(char arg[])
// {
// 	int i = 0;

// 	for (i = 0; arg[i] != '\0'; i++){
// 		char ch = arg[i];

// 		if (isalpha((int)ch) || isblank((int)ch)){
// 			printf("'%c' == %d \n",ch,ch);
// 		}
// 	}
// }

// int can_print_it(char ch)
// {
// 	return isalpha((int)ch) || isblank((int)ch);
// }

int main(int argc, char *argv[]){

	print_arguments(argc,argv);
	return 0;
}
