#include<stdio.h>

/*******************************************
Created By: Ankur Srivastava
About:      To Understand basic recursion.
*******************************************/

void fun(int n)
{
    if (n > 0)
    {
        printf("%d", n);
        fun(n-1);
    }
    return;
}


void main()
{
    int x = 3;
    fun(x);

    printf("\n");

    return;
}
