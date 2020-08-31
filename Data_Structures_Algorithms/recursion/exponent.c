/*********************************************************************
* Created By: Ankur Srivastava
* About:      To code exponent using recursion
*             with it's time and space Complexity.
*  
**********************************************************************/

#include<stdio.h>
#include<stdlib.h>

int expn(int base, int expo)
{
    if(expo == 0)
    {
        return 1;
    }
    else
    {
        return (base * expn(base, expo-1));
    }
}

int optexp(int base, int expo)
{
    if(expo == 0)
    {
        return 1;
    }
    
    if(expo%2 == 0)
    {
        return (optexp(base*base, expo/2));
    }
    else
    {
        return (base * optexp(base*base, (expo-1)/2));
    }
}


void main()
{
    int base, expo;
    scanf("%d %d", &base, &expo);
    printf("%d\n", expn(base, expo));
    printf("%d\n", optexp(base, expo));
    return;
}
