/*********************************************************************
* Created By: Ankur Srivastava
* About:      To Understand Tree recursion
*             with it's time and space Complexity.
* Total Calls: (2^(n+1)) - 1  
* Number of times Stack frames created/deleted: Equal to Total Calls.
* Maximum Height of the Stack: n+1
* Time Complexity: O(2^n)
* Space Complexity: O(n)  
**********************************************************************/

#include<stdio.h>
#include<stdlib.h>

const unsigned long long max_count =  2000000;
unsigned long long call_count = 0;

void foo(int n)
{
    if(call_count >= max_count)
    {
        printf("\nToo many calls now....exiting\n");
        printf("Total Calls: %lld\n", call_count);
        exit(0);
    }
    call_count++;
    if(n > 0)
    {
        printf("%d", n);
        foo(n-1);
        foo(n-1);
    }
    return;
}


void main()
{
    int n;
    scanf("%d", &n);
    foo(n);
    printf("\nTotal number of Calls: %lld\n", call_count);
    return;
}
