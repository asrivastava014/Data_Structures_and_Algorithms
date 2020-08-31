#include<stdio.h>

void main()
{
    int a = 0,b = 0;
	printf("Enter 2 numbers\n");
    scanf("%d %d", &a, &b);

    printf("Result: %d\n", ((a>b)?(a+b):(a-b)));
    return;

}
