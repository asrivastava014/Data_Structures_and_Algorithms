#include<stdio.h>
#define TRUE 1
#define PIE 3.14

void main()
{
    float radius = 0xFFFFFFFF;
	while(TRUE)
    {
        float area = 0xFFFFFFFF, perimeter = 0xFFFFFFFF;
		printf("Enter a radius of a circle you want the area/perimeter of.\n");
        scanf("%f",&radius);

        area = PIE * radius * radius;
        perimeter = 2 * PIE * radius;

        printf("Area = %f\nPerimeter = %f\n", area, perimeter);
	}
	return;
}
