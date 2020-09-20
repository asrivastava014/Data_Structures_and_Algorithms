/*********************************************************************
* Created By: Ankur Srivastava
* About:      To understand Array ADT with the Array Data and
*             associated operations.
* 
**********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "array_adt.h"


/*********************************************************************
* Function: swap_array_item
* About:    Swaps the array elements
*           
* 
**********************************************************************/
void swap_array_item(Array_ptr A, int curr_idx, int new_idx)
{
    int temp = A->A[new_idx];     

    A->A[new_idx]  = A->A[curr_idx];
    A->A[curr_idx] = temp; 
    
    return;
}


/*********************************************************************
* Function: swap_array_by_addr 
* About:    swap array elements by there addresses.
*           
* 
**********************************************************************/
void swap_array_by_addr(int *A, int *B)
{
    int temp = *B;     

    *B = *A;
	*A = temp;
 
    return;
}


/*********************************************************************
* Function: init_array 
* About:    initializes the array by memory allocation.
*           
* 
**********************************************************************/
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


/*********************************************************************
* Function: delete_array
* About:    deletes the array elements by de-allocationg memory
*           
* 
**********************************************************************/
void delete_array(Array_ptr array)
{
    free(array->A);
    array->size = 0;
    array->length = 0;
    printf("Array Memory Deallocated...\n");
    return;
}


/*********************************************************************
* Function:  display
* About:     displays the array elements.
*           
* 
**********************************************************************/
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


/*********************************************************************
* Function: append
* About:    inserts the element at the end of the array
*           
* 
**********************************************************************/
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


/*********************************************************************
* Function: insert
* About:    inserts the elements at the desired position in the array
*           
* 
**********************************************************************/
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


/*********************************************************************
* Function: delete_item
* About:    deleted an array element
*           
* 
**********************************************************************/
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


/*********************************************************************
* Function: linear_search
* About:    searching an element with linear search algo
*           
* 
**********************************************************************/
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


/*********************************************************************
* Function:  linear_search_transposition
* About:     changing the position of the searched element by pos-1
*           
* 
**********************************************************************/
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


/*********************************************************************
* Function: linear_search_move_to_head
* About:    if element found, moves the element to the head.
*           
* 
**********************************************************************/
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


/*********************************************************************
* Function: Bin_search 
* About:    Searching with sorted list.
*           
* 
**********************************************************************/
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


/*********************************************************************
* Function: Bin_Search_rec
* About:    Recursive Binary Searching
*           
* 
**********************************************************************/
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


/*********************************************************************
* Function: binary_search
* About:    Wrapper function
*           
* 
**********************************************************************/
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


/*********************************************************************
* Function: binary_search_rec
* About:    Wrapper function
*           
* 
**********************************************************************/
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
float avg(Array A)
{
    if(A.length == 0)
    {
        printf("Array Empty.\n");
        return ERR;
    }

    return (sum(A)/A.length);
}


/*********************************************************************
* Function: reverse
* About:    to reverse an array
*           
* 
**********************************************************************/
void reverse(Array_ptr A)
{
    int i, j;

    if(A->length == 0)
    {
        printf("Empty Array.\n");
        return;
    }

    int *B = (int *)malloc(sizeof(int) * A->length);

    for(i = 0, j = A->length-1; j >= 0; i++, j--)
    {
        B[i] = A->A[j];
    }

    for (i = 0; i < A->length; i++)
    {
        A->A[i] = B[i];
    }

    free(B);

    return;
}


/*********************************************************************
* Function: reverse_opt
* About:    optimized way of reversing an array.
*           
* 
**********************************************************************/
void reverse_opt(Array_ptr A)
{
    int i, j;

    if(A->length == 0)
    {
        printf("Empty Array.\n");
        return;
    }

    for(i = 0, j = A->length-1; i < j; i++, j--)
    {
        swap_array_item(A, i, j);
    }

    return;
}


/*********************************************************************
* Function: left shift
* About:    left shift the array
*           
* 
**********************************************************************/
void left_shift(Array_ptr A)
{
    int i;

    if(A->length == 0)
    {
        printf("Array Empty.\n");
        return;
    }

    for(i = 0; i < A->length-1; i++)
    {
        A->A[i] = A->A[i+1];
    }

    A->A[i] = 0;

    return;
}


/*********************************************************************
* Function: right_shift
* About:    right shift an array
*           
* 
**********************************************************************/
void right_shift(Array_ptr A)
{
    int i;

    if(A->length == 0)
    {
        printf("Array Empty.\n");
        return;
    }

    for(i = A->length-1; i > 0; i--)
    {
        A->A[i] = A->A[i-1];
    }

    A->A[i] = 0;

    return;
}


/*********************************************************************
* Function: left_rotate
* About:    rotating an array to the left
*           
* 
**********************************************************************/
void left_rotate(Array_ptr A)
{
    if(A->length == 0)
    {
        printf("Array Empty.\n");
        return;
    }

    int item = A->A[0];

    left_shift(A);
    A->A[A->length-1] = item;

    return;
}


/*********************************************************************
* Function: right_rotate
* About:    rotating an array to the right
*           
* 
**********************************************************************/
void right_rotate(Array_ptr A)
{
    if(A->length == 0)
    {
        printf("Array Empty.\n");
        return;
    }

    int item = A->A[A->length-1];

    right_shift(A);
    A->A[0] = item;

    return;
}


/*********************************************************************
* Function: inser_sorted
* About:    insertion sort algorithm
*           
* 
**********************************************************************/
void insert_sorted(Array_ptr A, int item)
{
    int i = A->length-1;

    if(A->length == A->size)
    {
        printf("Array full.\n");
        return;
    }

    while(i >= 0 && A->A[i] >= item)
    {
        if(item == A->A[i])
        {
            printf("Element already present at index: %d\n",i);
            return;
        }

        A->A[i+1] = A->A[i];
        i--;
    }

    A->A[i+1] = item;
    A->length++;

    return;
}


/*********************************************************************
* Function: is_sorted
* About:    check if an array is sorted
*           
* 
**********************************************************************/
bool is_sorted(Array A)
{
    if (A.length == 0)
    {
        printf("Array Empty.\n");
        return false;
    }

    for(int i = 0; i < A.length-1; i++)
    {
        if(A.A[i] > A.A[i+1])
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
void set_number_pos_neg(Array_ptr A)
{
    if(A->length == 0)
    {
        printf("Array is Empty.\n");
        return;
    }

    int i, j;

    i = 0;
    j = A->length-1;

    while(i < j)
    {
        while(A->A[i] < 0)  {i++;}
        while(A->A[j] >= 0) {j--;}

        if(i < j)
        {
            swap_array_item(A, i, j);
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
void merge_sort(Array A, Array B)
{
    if(0 == A.length && 0 == B.length)
    {
        printf("Arrays are Empty\n");
        return;
    }

    int i = 0, j = 0, k = 0;
    int total_size = A.length + B.length;

    int *C = (int *)malloc(sizeof(int) * total_size);

    if(!C)
    {
        printf("Not enough memory.\n");
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
            printf("Duplicate Value detected.\n");
            C[k++] = A.A[i++];
            j++;
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
        printf("%d\t", C[m]);
    }

    printf("\n");

    free(C);
}


/*********************************************************************
* Function: set_union_unsorted
* About:    A U B ==> Set operation for unsorted array
*           
* 
**********************************************************************/
void set_union_unsorted(Array A, Array B)
{
    if(0 == A.length && 0 == B.length)
    {
        printf("Arrays are Empty");
        return;
    }

    int i, j, k;
    int total_size = A.length + B.length;
    bool is_duplicate = false;

    int *C = (int *)malloc(sizeof(int) * total_size);

    if(!C)
    {
        printf("Memory not available.\n");
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
        printf("%d\t", C[i]);
    }
    printf("\n");

    free(C);

    return;
}


/*********************************************************************
* Function: set_union_sorted
* About:    A U B ==> Set operation for sorted arrays
*           
* 
**********************************************************************/
void set_union_sorted(Array A, Array B)
{
    if(0 == A.length && 0 == B.length)
    {
        printf("Arrays are Empty\n");
        return;
    }

    int total_size = A.length + B.length;

    int *C = (int *)malloc(sizeof(int) * total_size);

    if(!C)
    {
        printf("Memory not available.\n");
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
        printf("%d\t", C[i]);
    }
    printf("\n");

    free(C);

    return;
}


/*********************************************************************
* Function: set_intersec_unsorted
* About:    A intersec B ==> Set operation on unsorted arrays
*           
* 
**********************************************************************/
void set_intersec_unsorted(Array A, Array B)
{
    if(0 == A.length || 0 == B.length)
    {
        printf("Array(s) are Empty.\n");
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
    

    int *C = (int *)malloc(sizeof(int) * total_size);

    if(!C)
    {
        printf("Memory not available.\n");
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
        printf("%d\t", C[i]);
    }
    printf("\n");

    free (C);

    return;
}


/*********************************************************************
* Function: set_intersec_sorted
* About:    A intersec B ==> Set operation on sorted arrays
*           
* 
**********************************************************************/
void set_intersec_sorted(Array A, Array B)
{
    if(0 == A.length || 0 == B.length)
    {
        printf("Array(s) are Empty.\n");
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

    int *C = (int *)malloc(sizeof(int) * total_size);

    if(!C)
    {
        printf("Memory not available.\n");
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
        printf("%d\t", C[i]);
    }
    printf("\n");

    free (C);

    return;
}


/*********************************************************************
* Function: set_diff_unsorted
* About:    A - B ==> Set difference for unsorted arrays
*           
* 
**********************************************************************/
void set_diff_unsorted(Array A, Array B)
{
    if(0 == A.length || 0 == B.length)
    {
        printf("Array(s) are Empty.\n");
        return;
    }

    int total_size = A.length;  //since max size will be A
    bool is_duplicate = false;

    int *C = (int *)malloc(sizeof(int) * total_size);

    if(!C)
    {
        printf("Memory not available.\n");
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
        printf("%d\t", C[i]);
    }
    printf("\n");

    free (C);

    return;
}


/*********************************************************************
* Function: set_diff_sorted
* About:    A - B ==> Set difference for sorted arrays
* 
**********************************************************************/
void set_diff_sorted(Array A, Array B)
{
    if(0 == A.length || 0 == B.length)
    {
        printf("Array(s) are Empty.\n");
        return;
    }

    int total_size = A.length; //Since max size will be of A

    int *C = (int *)malloc(sizeof(int) * total_size);

    if(!C)
    {
        printf("Memory not available.\n");
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
        printf("%d\t", C[i]);
    }
    printf("\n");

    free (C);

    return;
}
