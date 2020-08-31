/*********************************************************************
* Created By: Ankur Srivastava
* About:      To Understand Indirect recursion
*             with it's time and space Complexity.
* Total Calls: 
* Number of times Stack frames created/deleted: 
* Maximum Height of the Stack:
* Time Complexity:
* Space Complexity:  
**********************************************************************/

#include<stdio.h>
#include<stdlib.h>

void A(int);
void B(int);


void A(int n)
{
    if(n > 0)
    {
        printf("%d\t", n);
        B(n-1);
    }
    return;
}


void B(int n)
{
    if(n > 1)
    {
        printf("%d\t", n);
        A(n/2);
    }
    return;
}


void main()
{
    int n;
    scanf("%d", &n);
    A(n);
    printf("\n");
    return;
}
