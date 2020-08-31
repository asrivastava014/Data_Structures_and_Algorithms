#include<stdio.h>
#define MAX 5

void main()
{
	int arr[MAX] = {0}, temp, i , j;

    for (i=0; i<MAX; i++)
    {
        printf("Enter Value %d: ", i+1);
        scanf("%d",&arr[i]);
    }

    printf("\n");
    printf("Value Entered:\n");

    for (i=0; i<MAX; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(i=0, j=MAX-1; i<j; i++,j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    printf("Reversed Array:\n");
    for (i=0; i<MAX; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

return;
}
