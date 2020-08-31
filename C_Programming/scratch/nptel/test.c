#include<stdio.h>
#define AVERAGE_DENOM 2
#define TRUE 1

void main()
{
   int a,b,average;
   while(TRUE)
   {  
        a = b = average = 0;
   		printf("Enter 2 even integers seperated by space\n");
        scanf("%d %d", &a, &b);
        
     	if(((a % 2) != 0) || ((b % 2) != 0))
        {
        	printf("Wrong integers entered, Please try again\n");
            continue;
        }
        else
        {
            average = (a+b)/AVERAGE_DENOM;
            printf("Average of %d and %d is %d\n", a, b, average);
            break;
        }
   }
   return;
}
