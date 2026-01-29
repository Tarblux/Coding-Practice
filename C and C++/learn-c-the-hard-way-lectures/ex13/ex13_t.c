#include <stdio.h>

static int giveVal(){
	return 1;
} 

int main(int argc , char *argv[])
{

	int i = 0;

	for (i = 1; i < argc ; i++){
		printf("arg %i: %s \n", i,argv[i]); 
	}


	char *states[] = {
		"California", "Oregon",
		"Washington", NULL
	};

	int num_states = 4;

	for ( i = giveVal() , i +=2 ; i < num_states; i++){

		printf("State %i: %s \n",i,states[i]);   
	}

	return 0;
}
