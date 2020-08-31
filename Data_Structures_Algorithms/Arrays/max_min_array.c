#include<stdio.h>
#define MAX 5

void main()
{
	int arr[MAX] = {0}, max, min,i;

    for (i=0; i<MAX; i++)
    {
    	printf("Enter value %d\n", i+1);
        scanf("%d",&arr[i]);
    }

    max = min = arr[0];
    for(i=1; i < MAX; i++)
    {
        if (max < arr[i])
			max = arr[i];
        if (min > arr[i])
			min = arr[i]; 
    }
    printf("Max is %d Min is %d\n", max, min);
return;
}
