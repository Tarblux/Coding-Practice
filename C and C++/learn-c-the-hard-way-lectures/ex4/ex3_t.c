#include <stdio.h>

void tariq()
{
    int age = 26;
    char *name = "tariq";

    printf("name is %s and age is %d",name,age);
}

int main(int argc, char *argv[])
{
    int age = 1000001;
    int height = 72;
	
    printf("I am %c years old.\n", age);
    printf("I am %i inches tall.\n", height);

    tariq();

    return 0;
}
