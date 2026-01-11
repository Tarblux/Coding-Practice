#include <stdio.h> 

/*This is a comment.*/
int main(int argc,char *argv[])
{
	int distance = 100;
	int mul = 3;
	char name[] = "tariq";

	// This is also a comment
	printf("You are %d miles away.\n",distance);
	printf("I think distance is good");
	printf("\n %s is a human",name);
	printf("\n %d is scaled distance",distance*mul);
	printf("\n %d ",distance+mul);
	printf("\n");

	return 0;
}
