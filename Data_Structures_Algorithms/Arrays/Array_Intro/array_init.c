/*********************************************************************
* Created By: Ankur Srivastava
* About:      To design realloc for arrays that is to
*             resize the array if it has underflowed/overflowed 
* 
**********************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void my_realloc(int **curr, int curr_size, int new_size)
{
    int *temp = (int *)malloc(sizeof(int)*new_size);
    
    memset(temp, 0, (sizeof(int) * new_size));

    for(int i = 0; i < curr_size; i++)
    {
        printf("%d\t", (*curr)[i]);
    }
    printf("\n");

    for(int i = 0; i < curr_size; i++)
    {
        temp[i] = (*curr)[i];
        printf("%d\t", temp[i]);
    }
    printf("\n");

    free(*curr);
    *curr = temp;
    temp = NULL;
    return;
}


void main()
{
    int *curr;

    curr = (int *)malloc(sizeof(int) * 6);
    
    for(int i = 0; i < 6; i++)
    {
        curr[i] = i+1;
        printf("%d\t", curr[i]);
    }
    printf("\n");

    my_realloc(&curr, 6, 10);

    for(int i = 0; i < 6; i++)
    {
        printf("%d\t", curr[i]);
    }
    printf("\n");
    free(curr);
}
