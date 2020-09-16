#include<stdio.h>
#define MAT1_ROW 5
#define MAT1_COL 5
#define MAT2_ROW 5
#define MAT2_COL 5
#define MAT3_ROW 5
#define MAT3_COL 5


void main()
{
    int mat1[3][3] = {
                        {1,2,3},
                        {4,5,6},
                        {7,8,9}
                     };
    int mat2[3][3] = {
                        {4,5,6},
                        {7,8,9},
                        {4,6,0}
                     };
    int mat3[2][3] = {
                        {1,2,3},
                        {4,5,6}
                     };
    
    int mat_res[3][3] = {0};
    int mat_res_mult[2][3] = {0};
    
    int i,j,k;
    
    /* Matrix Addition of mat1 and mat2 */
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            mat_res[i][j] = (mat1[i][j] + mat2[i][j]);       
        }
    }
    
    /* Matric Multiplication mat1 * mat3 */
    for(i=0;i<2;i++)
    {
        for(k=0;k<3;k++)
        {
            mat_res_mult[i][k] = 0;
            for(j=0;j<3;j++)
            {
                mat_res_mult[i][k] += (mat3[i][j] * mat2[j][k]);
            }
        }
    }
    
    /* Matric Addition Display */
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%5d", mat_res[i][j]);         
        }
        printf("\n");
    }
    
    printf("\n");
    
    /* Matric Multi Display */
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%5d", mat_res_mult[i][j]);         
        }
        printf("\n");
    }
return;
}
