#include<stdio.h>

/**********************************************
* Created By: Ankur Srivastava
* About:      To Understand basic recursion
*             with Static and Global Variable.
***********************************************/

int k = 5;

int foo1(int n)
{
    if(n > 0)
    {
        k++;
        return (foo1(n-1) + k);
    }

    return 0;
}

int foo(int n)
{
    static int x = 0;
    if(n > 0)
    {
        x++;
        return (foo(n-1) + x);
    }

    return 0;
}


void main()
{
    int a = 5;
    printf("%d\n", foo(a));

    printf("%d\n", foo1(a));

    return;
}
