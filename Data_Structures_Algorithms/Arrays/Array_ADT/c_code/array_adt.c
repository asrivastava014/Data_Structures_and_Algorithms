/*********************************************************************
* Created By: Ankur Srivastava
* About:      To understand Array ADT with the Array Data and
*             associated operations.
* 
**********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "array_adt.h"


void swap_array_item(int *A, int curr_idx, int new_idx)
{
    int temp = A[new_idx];     

    A[new_idx]  = A[curr_idx];
    A[curr_idx] = temp; 
    
    return;
}

void swap_array_by_addr(int *A, int *B)
{
    int temp = *B;     

    *B = *A;
	*A = temp;
 
    return;
}

void init_array(Array_ptr array, int size)
{
    if(array->A != NULL)
    {
        printf("Memory is already allocated\n");
        return;
    }

    array->A = (int *)malloc(sizeof(int) * size);
    if(!array->A)
    {
        printf("Array Memory cannot be allocated...\n");
    }
    else
    {
        printf("Array Memory Allocated with size %d\n", size);
        array->size = size;
        array->length = 0;
    }
    return;
}

void delete_array(Array_ptr array)
{
    free(array->A);
    array->size = 0;
    array->length = 0;
    printf("Array Memory Deallocated...\n");
    return;
}

void display(Array array)
{
    if (array.length == 0)
    {
        printf("Empty Array..\n");
    }

    for(int i = 0; i < array.length; i++)
    {
        printf("[%d]->%d\t", i, array.A[i]);
    }
    printf("\n");

    return;
}

void append(Array_ptr array, int item)
{
    if(array->length == array->size)
    {
        printf("Array is full....\n");
        return;
    }
    
    array->A[array->length++] = item;
    return;
}

void insert(Array_ptr array, int idx, int item)
{
    if(array->length == array->size)
    {
        printf("Array is full....\n");
        return;
    }

    if (idx < 0 || idx > array->length)
    {
        printf("Index should be between 1 to %d\n.", array->length);
        return;
    }
   
    for(int i = array->length; i > idx; i--)
    {
        array->A[i] = array->A[i-1];
    }
    array->A[idx] = item;
    array->length++;
    
    return;
}


int delete_item(Array_ptr array, int idx)
{
    int item = -1;
    if (array->length == 0)
    {
        printf("Empty Array..\n");
    }
    else
    {
        if (idx >= 0 && idx < array->length)
        {
            item = array->A[idx];
            for(int i = idx; i < array->length - 1; i++)
            {
                array->A[i] = array->A[i+1];
            }
            array->length--;
        }
        else
        {
            printf("Wrong Index Entered\n");
        }
    }
    return item;
}

int linear_search(Array array, int key)
{
    int res = ERR;
    if (array.length == 0)
    {
        printf("Empty Array\n");
    }
    else
    {    
        for(int i = 0; i < array.length; i++)
        {
            if(array.A[i] == key)
            {
                res = i;
                break;
            }
        }
    }
    return res;
}

int linear_search_transposition(Array_ptr array, int key)
{
    int res = ERR;
    if (array->length == 0)
    {
        printf("Empty Array\n");
    }
    else
    {    
        for(int i = 0; i < array->length; i++)
        {
            if(array->A[i] == key)
            {
                //swap_array_item(array->A, i, i-1);
				swap_array_by_addr(&array->A[i], &array->A[i-1]);
                res = i-1;
                break;
            }
        }
    }
    return res;
}


int linear_search_move_to_head(Array_ptr array, int key)
{
    int res = ERR;
    if (array->length == 0)
    {
        printf("Empty Array\n");
    }
    else
    {    
        for(int i = 0; i < array->length; i++)
        {
            if(array->A[i] == key)
            {
                //swap_array_item(array->A, i, 0);              
				swap_array_by_addr(&array->A[i], &array->A[0]);
                res = 0;
                break;
            }
        }
    }
    return res;
}

int Bin_Search(Array array, int low, int high, int key)
{
    while(low <= high)
    {
        int mid = (low+high)/2;

        if(key == array.A[mid])
        {
            return mid;
        }
        else if(key < array.A[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    
    return ERR;
}


int Bin_Search_rec(Array array, int low, int high, int key)
{
    if(low <= high)
    {
        int mid = (low+high)/2;

        if(key == array.A[mid])
        {
            return mid;
        }
        else if(key < array.A[mid])
        {
            return Bin_Search_rec(array, low, mid-1, key);
        }
        else
        {
            return Bin_Search_rec(array, mid+1, high, key);
        }
    }
    return ERR;
}


int binary_search(Array array, int key)
{
    int low = 0, high = array.length-1;

    if (array.length == 0)
    {
        printf("Empty Array..\n");
        return ERR;
    }
    
    return Bin_Search(array, low, high, key);
}


int binary_search_rec(Array array, int key)
{
    int low = 0, high = array.length-1;

    if (array.length == 0)
    {
        printf("Empty Array..\n");
        return ERR;
    }
    
    return Bin_Search_rec(array, low, high, key);
}


/*********************************************************************
* Function: get_item_at_index
* About:    getting an element at a given index
*           
* 
**********************************************************************/
int  get_item_at_index(Array A, int idx)
{
    if (idx >= 0 && idx < A.length)
    {
        return A.A[idx];
    }

    printf("Array Empty OR Index is wrong, Length: %d\n", A.length);
    return ERR;
}

/*********************************************************************
* Function: set_item_at_index
* About:    set an element at a given index.
*           
* 
**********************************************************************/
void  set_item_at_index(Array_ptr A, int idx, int item)
{
    if (idx >= 0 && idx < A->length)
    {
        A->A[idx] = item;
        return;
    }

    printf("Array Empty OR Index is wrong, Length: %d\n", A->length);
}


/*********************************************************************
* Function: Max
* About:    to find the max element from the array.
* 
**********************************************************************/
int Max(Array A)
{
    if(A.length == 0)
    {
        printf("Array is Empty.\n");
        return ERR;
    }

    int max = A.A[0];

    for(int i = 1; i < A.length; i++)
    {
        if(max < A.A[i])
        {
            max = A.A[i];
        }
    }

    return max;
}


/*********************************************************************
* Function: Min
* About:    to find the Min element of a given array
*           
* 
**********************************************************************/
int Min(Array A)
{
    if(A.length == 0)
    {
        printf("Array is Empty.\n");
        return ERR;
    }

    int min = A.A[0];

    for(int i = 1; i < A.length; i++)
    {
        if(min > A.A[i])
        {
            min = A.A[i];
        }
    }

    return min;
}


/*********************************************************************
* Function: sum
* About:    To calculate the sum of all the elements of an array
*           
* 
**********************************************************************/
int sum(Array A)
{
    if(A.length == 0)
    {
        printf("Array is Empty\n");
        return 0;
    }

    int sum = 0;

    for(int i = 0; i < A.length; i++)
    {
        sum += A.A[i];
    }

    return sum;
}


/*********************************************************************
* Function: _sum_rec
* About:    Helper function for recursive sum
*           
* 
**********************************************************************/
int _sum_rec(Array A, int n)
{
    if(n < 0)
    {
        return 0;
    }
    else
    {
        return A.A[n] + _sum_rec(A, n-1);
    }
}


/*********************************************************************
* Function: sum_rec
* About:    To calculate the sum of array recursively.
*           
* 
**********************************************************************/
int sum_rec(Array A)
{
    if(A.length == 0)
    {
        printf("Array Empty.\n");
        return 0;
    }

    return _sum_rec(A, A.length - 1);
}


/*********************************************************************
* Function: avg
* About:    To calculate avg of given array
*           
* 
**********************************************************************/
float Array::avg()
{
    if(length == 0)
    {
        cout<<"Array Empty"<<endl;
        return ERR;
    }

    return (sum()/length);
}


/*********************************************************************
* Function: reverse
* About:    to reverse an array
*           
* 
**********************************************************************/
void Array::reverse()
{
    int i, j;

    if(length == 0)
    {
        cout<<"Empty Array."<<endl;
        return;
    }

    int *B = new int[length];

    for(i = 0, j = length-1; j >= 0; i++, j--)
    {
        B[i] = A[j];
    }

    for (i = 0; i < length; i++)
    {
        A[i] = B[i];
    }

    delete[] B;

    return;
}


/*********************************************************************
* Function: reverse_opt
* About:    optimized way of reversing an array.
*           
* 
**********************************************************************/
void Array::reverse_opt()
{
    int i, j, temp;

    if(length == 0)
    {
        cout<<"Empty Array."<<endl;
        return;
    }

    for(i = 0, j = length-1; i < j; i++, j--)
    {
        swap_array_item(i, j);
    }

    return;
}


/*********************************************************************
* Function: left shift
* About:    left shift the array
*           
* 
**********************************************************************/
void Array::left_shift()
{
    int i;

    if(length == 0)
    {
        cout<<"Array Empty."<<endl;
        return;
    }

    for(i = 0; i < length-1; i++)
    {
        A[i] = A[i+1];
    }

    A[i] = 0;

    return;
}


/*********************************************************************
* Function: right_shift
* About:    right shift an array
*           
* 
**********************************************************************/
void Array::right_shift()
{
    int i;

    if(length == 0)
    {
        cout<<"Array Empty."<<endl;
        return;
    }

    for(i = length-1; i > 0; i--)
    {
        A[i] = A[i-1];
    }

    A[i] = 0;

    return;
}


/*********************************************************************
* Function: left_rotate
* About:    rotating an array to the left
*           
* 
**********************************************************************/
void Array::left_rotate()
{
    if(length == 0)
    {
        cout<<"Array Empty."<<endl;
        return;
    }

    int item = A[0];

    left_shift();
    A[length-1] = item;

    return;
}


#if 0
/*********************************************************************
* Function: right_rotate
* About:    rotating an array to the right
*           
* 
**********************************************************************/
void Array::right_rotate()
{
    if(length == 0)
    {
        cout<<"Array Empty."<<endl;
        return;
    }

    int item = A[length-1];

    right_shift();
    A[0] = item;

    return;
}


/*********************************************************************
* Function: inser_sorted
* About:    insertion sort algorithm
*           
* 
**********************************************************************/
void Array::insert_sorted(int item)
{
    int i = length-1;

    if(length == size)
    {
        cout<<"Array full."<<endl;
        return;
    }

    while(i >= 0 && A[i] >= item)
    {
        if(item == A[i])
        {
            cout<<"Element already present at index: "<<i<<endl;
            return;
        }

        A[i+1] = A[i];
        i--;
    }

    A[i+1] = item;
    length++;

    return;
}


/*********************************************************************
* Function: is_sorted
* About:    check if an array is sorted
*           
* 
**********************************************************************/
bool Array::is_sorted()
{
    if (length == 0)
    {
        cout<<"Array Empty."<<endl;
    }

    for(int i = 0; i < length-1; i++)
    {
        if(A[i] > A[i+1])
        {
            return false;
        }
    }

    return true;
}


/*********************************************************************
* Function: set_number_pos_neg
* About:    putting negative numbers at left and positive at right
*           
* 
**********************************************************************/
void Array::set_number_pos_neg()
{
    if(length == 0)
    {
        cout<<"Array is Empty."<<endl;
        return;
    }

    int i, j;

    i = 0;
    j = length-1;

    while(i < j)
    {
        while(A[i] < 0)  {i++;}
        while(A[j] >= 0) {j--;}

        if(i < j)
        {
            swap_array_item(i, j);
        }
    }

    return;
}


/*********************************************************************
* Function: merge_sort
* About:    merge_sort algorithm
*           
* 
**********************************************************************/
void merge_sort(Array& A, Array& B)
{
    if(0 == A.length && 0 == B.length)
    {
        cout<<"Arrays are Empty"<<endl;
        return;
    }

    int i = 0, j = 0, k = 0;
    int total_size = A.length + B.length;

    int *C = new int[total_size];

    if(!C)
    {
        cout<<"Not enough memory."<<endl;
        return;
    }

    while(i < A.length && j < B.length)
    {
        if(A.A[i] < B.A[j])
        {
            C[k++] = A.A[i++];
        }
        else if(A.A[i] > B.A[j]) 
        {
            C[k++] = B.A[j++];
        }
        else
        {
            cout<<"Duplicate Value detected."<<endl;
            C[k++] = A.A[i++];
            C[k++] = B.A[j++];
        }
    }

    for(; i<A.length; i++)
    {
        C[k++] = A.A[i];
    }

    for(; j<B.length; j++)
    {
        C[k++] = B.A[j];
    }

    for(int m = 0; m < total_size; m++)
    {
        cout<<C[m]<<"\t";
    }

    cout<<endl;

    delete[] C;
}


/*********************************************************************
* Function: set_union_unsorted
* About:    A U B ==> Set operation for unsorted array
*           
* 
**********************************************************************/
void set_union_unsorted(Array& A, Array& B)
{
    if(0 == A.length && 0 == B.length)
    {
        cout<<"Arrays are Empty"<<endl;
        return;
    }

    int i, j, k;
    int total_size = A.length + B.length;
    bool is_duplicate = false;

    int *C = new int[total_size];

    if(!C)
    {
        cout<<"Memory not available."<<endl;
        return;
    }

    for(i = 0; i < A.length; i++)
    {
        C[i] = A.A[i];
    }

    k = A.length;

    for(j = 0; j < B.length; j++)
    {
        is_duplicate = false;

        for(i = 0; i < A.length; i++)
        {
            if (B.A[j] == A.A[i])
            {
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate)
        {
            C[k++] = B.A[j];
        }
    }

    for(i = 0; i < total_size; i++)
    {
        cout<<C[i]<<"\t";
    }
    cout<<endl;

    delete[] C;

    return;
}


/*********************************************************************
* Function: set_union_sorted
* About:    A U B ==> Set operation for sorted arrays
*           
* 
**********************************************************************/
void set_union_sorted(Array& A, Array& B)
{
    if(0 == A.length && 0 == B.length)
    {
        cout<<"Arrays are Empty"<<endl;
        return;
    }

    int total_size = A.length + B.length;

    int *C = new int[total_size];

    if(!C)
    {
        cout<<"Memory not available."<<endl;
        return;
    }

    int i = 0, j = 0, k = 0;

    while(i < A.length && j < B.length)
    {
        if(A.A[i] < B.A[j])
        {
            C[k++] = A.A[i++];

        }
        else if (A.A[i] > B.A[j])
        {
            C[k++] = B.A[j++];
        }
        else
        {
            C[k++] = A.A[i++];
            j++;
        }
    }

    for(; i < A.length; i++)
    {
        C[k++] = A.A[i];
    }

    for(; j < B.length; j++)
    {
        C[k++] = B.A[j];
    }
    
    for(i = 0; i < total_size; i++)
    {
        cout<<C[i]<<"\t";
    }
    cout<<endl;

    delete[] C;

    return;
}


/*********************************************************************
* Function: set_intersec_unsorted
* About:    A intersec B ==> Set operation on unsorted arrays
*           
* 
**********************************************************************/
void set_intersec_unsorted(Array& A, Array& B)
{
    if(0 == A.length || 0 == B.length)
    {
        cout<<"Array(s) are Empty"<<endl;
        return;
    }

    int i, j, k, total_size;
    bool is_duplicate = false;

    if(A.length < B.length)
    {
        total_size = A.length;
    }
    else
    {
        total_size = B.length;
    }
    

    int *C = new int[total_size];

    if(!C)
    {
        cout<<"Memory not available."<<endl;
        return;
    }

    k = 0;

    for(j = 0; j < B.length; j++)
    {
        is_duplicate = false;
        for(i = 0; i < A.length; i++)
        {
            if (B.A[j] == A.A[i])
            {
                is_duplicate = true;
                break;
            }
        }
        if (is_duplicate)
        {
            C[k++] = B.A[j];
        }
    }

    for(i = 0; i < total_size; i++)
    {
        cout<<C[i]<<"\t";
    }
    cout<<endl;

    delete[] C;

    return;
}


/*********************************************************************
* Function: set_intersec_sorted
* About:    A intersec B ==> Set operation on sorted arrays
*           
* 
**********************************************************************/
void set_intersec_sorted(Array& A, Array& B)
{
    if(0 == A.length || 0 == B.length)
    {
        cout<<"Array(s) are Empty"<<endl;
        return;
    }

    int total_size;

    if(A.length < B.length)
    {
        total_size = A.length;
    }
    else
    {
        total_size = B.length;
    }

    int *C = new int[total_size];

    if(!C)
    {
        cout<<"Memory not available."<<endl;
        return;
    }

    int i = 0, j = 0, k = 0;

    while(i < A.length && j < B.length)
    {
        if(A.A[i] < B.A[j])
        {
            i++;

        }
        else if (A.A[i] > B.A[j])
        {
            j++;
        }
        else
        {
            C[k++] = A.A[i++];
            j++;
        }
    }

    for(i = 0; i < total_size; i++)
    {
        cout<<C[i]<<"\t";
    }
    cout<<endl;

    delete[] C;

    return;
}


/*********************************************************************
* Function: set_diff_unsorted
* About:    A - B ==> Set difference for unsorted arrays
*           
* 
**********************************************************************/
void set_diff_unsorted(Array& A, Array& B)
{
    if(0 == A.length || 0 == B.length)
    {
        cout<<"Array(s) are Empty"<<endl;
        return;
    }

    int total_size = A.length;  //since max size will be A
    bool is_duplicate = false;

    int *C = new int[total_size];

    if(!C)
    {
        cout<<"Memory not available."<<endl;
        return;
    }

    int i = 0, j = 0, k = 0;

    for(j = 0; j < B.length; j++)
    {
        is_duplicate = false;
        for(i = 0; i < A.length; i++)
        {
            if (A.A[j] == B.A[i])
            {
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate)
        {
            C[k++] = A.A[j];
        }
    }

    for(i = 0; i < total_size; i++)
    {
        cout<<C[i]<<"\t";
    }
    cout<<endl;

    delete[] C;

    return;
}


/*********************************************************************
* Function: set_diff_sorted
* About:    A - B ==> Set difference for sorted arrays
* 
**********************************************************************/
void set_diff_sorted(Array& A, Array& B)
{
    if(0 == A.length || 0 == B.length)
    {
        cout<<"Array(s) are Empty"<<endl;
        return;
    }

    int total_size = A.length; //Since max size will be of A

    int *C = new int[total_size];

    if(!C)
    {
        cout<<"Memory not available."<<endl;
        return;
    }

    int i = 0, j = 0, k = 0;

    while(i < A.length && j < B.length)
    {
        if(A.A[i] < B.A[j])
        {
            C[k++] = A.A[i++];
        }
        else if (A.A[i] > B.A[j])
        {
            j++;
        }
        else
        {
            j++;
            i++;
        }
    }

    for(; i < A.length; i++)
    {
        C[k++] = A.A[i];
    }

    for(i = 0; i < total_size; i++)
    {
        cout<<C[i]<<"\t";
    }
    cout<<endl;

    delete[] C;

    return;
}

int  Array::get_item_at_index(int idx)
{
    return 0;
}

void Array::set_index(int idx)
{

}

int Array::Max()
{

}

int Array::Min()
{
    return 0;
}

void Array::reverse()
{

}

void Array::shift()
{

}

void Array::rotate()
{

}

#endif

