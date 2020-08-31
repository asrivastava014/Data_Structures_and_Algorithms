#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define TRUE  1
#define FALSE 0
#define MAX   10
#define CONVERSION_CONSTANT 1.8
#define MAX_DECIMAL_COUNT   1

void main()
{
	float temp_celsius = 0xFFFFFFFF;
    char temp[MAX] = {'\0'};
    int i = 0;
    bool invalid_flag = FALSE;
    int decimal_count = 0;
 
	while(TRUE)
    {
        i = 0;
    	invalid_flag = FALSE;
 		decimal_count = 0;

		printf("Enter the value in degree celsius\n");
        scanf("%s",temp);
        if (strlen(temp) >= MAX)
 		{
			printf("Wierd/Long digit combination entered\n");
            continue;
		}
        
        while(i < strlen(temp))
        {
            if (decimal_count > MAX_DECIMAL_COUNT)
            {
                printf("Input contains multiple decimal points\n");
                invalid_flag = TRUE;
                break;
            }
            if (temp[i] == 32)
            {
                printf("Space is not allowed\n");
                invalid_flag = TRUE;
                break;
            }
			if (temp[i] < 48 || temp[i] > 57)
 			{
				if (temp[i] == 46)
				{
                    i++;
                    decimal_count++;
                    continue;
                }
                else
                {
					printf("Input contains symbols or unwanted characters.\n");
                    invalid_flag = TRUE;
                    break;
				}
			}
        	i++;
        }
        if (invalid_flag)
        {
			continue;
        }
		temp_celsius = atof(temp);
        printf("entered value is = %f\n",temp_celsius);
        
        /* Calculate and display the Temperature in Fahrenheit */    
        printf("Temperature in Fahrenhiet: %f\n", ((temp_celsius * CONVERSION_CONSTANT) + 32));
	}
return;
}
