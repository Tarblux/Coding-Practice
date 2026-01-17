#include <stdio.h>

static void ifStatement()
{	
	int age = 20;

	if(age >= 21){
		printf("You can legally drink because you are %i",age);
	} else if (age == 16){
		printf("Run Before I call the cops !!");
	} else {
		age ++;
	} 

}

static int switchStatement(int response_code)
{	
	
	switch(response_code){
		case 400:
			return 0;
			break;
		case 200:
			return 1;
			break;
		default:
			return 0;
			break;
	}
}

static void wildLoop()
{
	int i = 0;

	while(i < 10){
		printf("This is iteration : %i \n ",i);
		i ++;
	}
}

int main()
{
	ifStatement();

	int result = switchStatement(200);
	printf("%i \n",result);

	wildLoop();

	return 0;
}
