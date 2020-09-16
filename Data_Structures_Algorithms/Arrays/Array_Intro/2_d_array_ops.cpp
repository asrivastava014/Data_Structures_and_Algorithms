/*********************************************************************
* Created By: Ankur Srivastava
* About:      To understand 3 ways of declaring 2-D arrays
*             1. A[][] ==> Full array in stack.
*             2. *A[]  ==> Array of pointers.(Partial in Heap).
*             3. **A   ==> Full Array in Heap.
* 
**********************************************************************/


#include <bits/stdc++.h>

#define ROW 3
#define COL 4

using namespace std;

void display_2d(int *A)
{
    cout<<"Single pointer.."<<endl;
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			cout<<*((A + i * COL) + j)<<"\t";
		}
	}
    cout<<endl;
}


void display_array(int (*A)[COL], int **B, int **C)
{
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			cout<<*(*(A+i)+j)<<"\t";
		}
	}
    cout<<endl;

    for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			cout<<*(*(B+i)+j)<<"\t";
		}
	}
    cout<<endl;

	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			cout<<*(*(C+i)+j)<<"\t";
		}
	}
    cout<<endl;
}



int main()
{
    int A[ROW][COL] = {
					   	{2,4,6,7},
						{8,12,13,14},
						{44,56,66,77}
                      };

	int *B[ROW];

    int AB[5];

	for(int i = 0; i < ROW; i++)
	{
		B[i] = new int[COL];
	}

	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			B[i][j] = A[i][j];
		}	
	}

	int **C;

    C = new int* [ROW];

    for(int i = 0; i < ROW; i++)
	{
		C[i] = new int[COL];
	}

	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			C[i][j] = A[i][j];
		}	
	}

	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			cout<<A[i][j]<<"\t";
		}
	}
    cout<<endl;

	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			cout<<B[i][j]<<"\t";
		}	
	}
    cout<<endl;

	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			cout<<B[i][j]<<"\t";
		}	
	}
    cout<<endl;

    cout<<"Calling...."<<endl;

    display_array(A, B, C);
    display_2d((int *)A);

    for(int i = 0; i < ROW; i++)
	{
		delete[] B[i];
	}

    for(int i = 0; i < ROW; i++)
	{
		delete[] C[i];
	}

    delete[] C;    

    return 0;
}
