#include <stdio.h>

static void extraWhile ( int nums[] , int len)
{	
	int i = 0;

	while (i != len ){
		printf("%p -> %i \n", (void*) &nums[i] , nums[i]);
		i++;
	}
}

int main ( int agrc , char *argv[])
{	
	int nums[] = {1,0,4,3,9};
	extraWhile(nums,4);

	int i = -1;

	while (i > -1){
		printf("%i \n",i);
		i--;
	}

}