#include <stdio.h>

/*

A = 65 , a = 97  

diff = 97 - 65 = 32 

ex given B

B = 66 + 32 = 98
98 -> b 


a =  (66 + 32) - 97  % 122 = 1


*/ 

// int static len(


int main(int argc, char *argv[])
{
	if (argc < 2){

		printf("ERROR: You need only one argument. \n");
		return 1;
	}

	int i = 0;
	int j = 0;
	char letter;

	for (j = 1 ; j < argc ; j++){ 

		for(i = 0 ,letter = argv[j][0]; letter != '\0' ; i++ , letter = argv[j][i]){

			int asc_val = (int) letter;

			if (asc_val < 97){
				asc_val = ((int) letter + 32 );
			}

			switch (asc_val){
				case 97:
					printf("%d: 'A'\n",i);
					break;

				case 101:
					printf("%d: 'E'\n",i);
					break;

				case 105:
					printf("%d: 'I'\n",i);
					break;

				case 111:
					printf("%d: 'O'\n",i);
					break;

				case 117:
					printf("%d: 'U'\n",i);
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
		printf("\n");
	}
}