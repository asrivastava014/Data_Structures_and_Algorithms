#include<stdio.h>
#include<malloc.h>

void change(int *av, int *ab)
{

    (*av)++;
    (*ab)++;

}

int *foo()
{
	int *k = (int *)malloc(sizeof(int));
	*k = 10;
    return k;
}

void main()
{
	int a = 10;
    int b = 11;

	printf("%d %d\n", a, b);
	change(&a, &b);
	printf("%d %d\n", a, b);

    int *bb = foo();

	printf("%d\n", *bb);

	free(bb);

	return;

}
