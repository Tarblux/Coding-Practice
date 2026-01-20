#include <stdio.h>

int len(char *arr[])
{
    int i = 0;
    while (arr[i] != NULL) i++;
    return i;
}

static void numsArray()
{ 
	int nums[] = {1,0,1};
	int i = 0;

	for (i = 0 ; i < sizeof(nums)/sizeof(nums[0]); i++){
		printf("%i \n",nums[i]);
	}
}


int main(int argc,char *argv[])
{
	int i = 0;

	if(argc==2){
		printf("You only have one argument. You Suck.\n");
	}else if (argc > 1 && argc < 4){
		printf("Here's your arguments:\n");

		for (i = 0; i < argc; i++) {
			printf("%s " , argv[i]);
		}

		printf("\n");
	}else if (argc >= 5){
		printf("You have too many arguments. You Suck.\n");
	}else{
		printf("No arguments provided.\n" );
	}

	numsArray();
}