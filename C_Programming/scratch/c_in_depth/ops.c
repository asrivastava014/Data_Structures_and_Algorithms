#include<stdio.h>
#include<inttypes.h>


void main()
{
    int x = 5, y = 0;

    y = (++x) + (--x);

    printf("%d\n",y); 

    return;
}
