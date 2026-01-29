#include <stdio.h>

void show_pointer_ladder(void)
{
    int x = 8;
    int *p = &x;
    int **pp = &p;

    printf("LEVEL 0 (value)\n");
    printf("x  = %d\n", x);
    printf("&x = %p\n\n", (void*)&x);

    printf("LEVEL 1 (pointer)\n");
    printf("p   = %p  (points to x)\n", (void*)p);
    printf("&p  = %p\n", (void*)&p);
    printf("*p  = %d  (value of x)\n\n", *p);

    printf("LEVEL 2 (pointer to pointer)\n");
    printf("pp   = %p  (points to p)\n", (void*)pp);
    printf("&pp  = %p\n", (void*)&pp);
    printf("*pp  = %p  (value of p)\n", (void*)*pp);
    printf("**pp = %d  (value of x)\n", **pp);
}

int main(void)
{
    show_pointer_ladder();
    return 0;
}