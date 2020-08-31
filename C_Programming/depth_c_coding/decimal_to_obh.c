#include<stdio.h>

void main()
{
	int octal[100], a;
    int i = 0, j = 0;

    printf("Enter a Integer Value\n");
    scanf("%d", &a);

    while(a != 0)
    {
        octal[i++] = a % 8;
        a /= 8; 
    }

    for (j = i-1; j >= 0; j--)
    {
        printf("%d", octal[j]);
    }
    printf("\n");

    return;
}
