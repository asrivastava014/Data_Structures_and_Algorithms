#include<stdio.h>


void main()
{
    int a = 0xFFFFFFFF, b = 0, count = 0, result = 0;
    while (1)
    {
        a = 0xFFFFFFFF, b = 0, count = 0, result = 0;
    	printf("Enter a 5 digit number\n");
        scanf("%d", &a);

        b = a;

        while(b != 0)
        {
            b /= 10;
            count++;
        }
        if (count > 5)
        {
            printf("You have entered more then 5 digits \n");
            continue;
        }
        else
        {
            result = a % 3;
            printf("Remainder when %d divided by 3 is: %d\n", a, result);
        }
    }
return;
}
