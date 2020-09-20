/*********************************************************************
* Created By: Ankur Srivastava
* About:      To understand Array ADT with the Array Data and
*             associated operations.
* 
**********************************************************************/


#include <bits/stdc++.h>
#include "array_adt.h"

using namespace std;


/*********************************************************************
* Function: Default Constructor
* About:    Sets all the member function to it's default 
*           value.
*           
* 
**********************************************************************/
Array::Array()
{
    A = new int[MAX_SIZE];
    if(!A)
    {
        cout<<"Array Memory cannot be allocated..."<<endl;
    }
    else
    {
        cout<<"Array Memory Allocated with default size "<<MAX_SIZE<<endl;
        size = MAX_SIZE;
    }
}


/*********************************************************************
* Function: Parameterized Constructor
* About:    Initializes all the member variable as per the
*           parameter passed.
* 
**********************************************************************/
Array::Array(int size)
{
    A = new int[size];
    if(!A)
    {
        cout<<"Array Memory cannot be allocated..."<<endl;
    }
    else
    {
        cout<<"Array Memory Allocated with size "<<size<<endl;
        this->size = size;
    }
}


/*********************************************************************
* Function: Destructor
* About:    De-allocates all the memory.
* 
**********************************************************************/
Array::~Array()
{
    delete[] A;
    this->size = 0;
    this->length = 0;
    cout<<"Array Memory Deallocated..."<<endl;
}


/*********************************************************************
* Function: swap_array_item
* About:    Helper function to swap 2 array locations.
* 
**********************************************************************/
void Array::swap_array_item(int curr_idx, int new_idx)
{
    int temp = A[new_idx];     

    A[new_idx]  = A[curr_idx];
    A[curr_idx] = temp; 
    
    return;
}


/*********************************************************************
* Function: init_array
* About:    Alternative of Constructor, a setter function.
* 
**********************************************************************/
void Array::init_array(int size)
{
    if(!A)
    {
        A = new int[size];
        if(!A)
        {
            cout<<"Array Memory cannot be allocated..."<<endl;
        }
        else
        {
            cout<<"Array Memory Allocated with size "<<size<<endl;
            this->size = size;
        }
    }
    else
    {
        cout<<"Array Memory is already allocated...."<<endl;
    }
    return;
}


/*********************************************************************
* Function: delete_array
* About:    de-allocates and deletes the dynamic array.
* 
**********************************************************************/
void Array::delete_array()
{
    delete[] A;
    this->size = 0;
    this->length = 0;
    cout<<"Array Memory Deallocated..."<<endl;
    return;
}


/*********************************************************************
* Function: display
* About:    Traverses and displays the array elements.
*           
* 
**********************************************************************/
void Array::display()
{
    if (length == 0)
    {
        cout<<"Empty Array.."<<endl;
        return;
    }

    for(int i = 0; i < length; i++)
    {
        cout<<"["<<i<<"]"<<"->"<<A[i]<<"\t";
    }
    cout<<endl;

    return;
}


/*********************************************************************
* Function: append
* About:    appends a item at the last location.
* 
**********************************************************************/
void Array::append(int item)
{
    if(length == size)
    {
        cout<<"Array is full...."<<endl;
        return;
    }
    
    A[length++] = item;
    return;
}


/*********************************************************************
* Function: insert
* About:    insert an element at a given location
* 
**********************************************************************/
void Array::insert(int idx, int item)
{
    if(length == size)
    {
        cout<<"Array is full...."<<endl;
        return;
    }

    if (idx < 0 || idx > length)
    {
        cout<<"Index should be between 0 to "<<length<<endl;
        return;
    }
   
    for(int i = length; i > idx; i--)
    {
        A[i] = A[i-1];
    }
    A[idx] = item;
    length++;
    
    return;
}


/*********************************************************************
* Function: delete_item
* About:    deletes an element from the array
*           
* 
**********************************************************************/
int Array::delete_item(int idx)
{
    int item = -1;
    if (length == 0)
    {
        cout<<"Empty Array.."<<endl;
    }
    else
    {
        if (idx >= 0 && idx < length)
        {
            item = A[idx];
            for(int i = idx; i < length - 1; i++)
            {
                A[i] = A[i+1];
            }
            length--;
        }
        else
        {
            cout<<"Wrong Index Entered\n";
        }
    }
    return item;
}


/*********************************************************************
* Function: linear_search
* About:    searches an element by linear search Algo
* 
**********************************************************************/
int Array::linear_search(int key)
{
    int res = ERR;
    if (length == 0)
    {
        cout<<"Empty Array"<<endl;
    }
    else
    {    
        for(int i = 0; i < length; i++)
        {
            if(A[i] == key)
            {
                res = i;
                break;
            }
        }
    }
    return res;
}


/*********************************************************************
* Function: linear_search_transposition
* About:    searching with the optimized linear search.
* 
**********************************************************************/
int Array::linear_search_transposition(int key)
{
    int res = ERR;
    if (length == 0)
    {
        cout<<"Empty Array"<<endl;
    }
    else
    {    
        for(int i = 0; i < length; i++)
        {
            if(A[i] == key)
            {
                swap_array_item(i, i-1);                
                res = i-1;
                break;
            }
        }
    }
    return res;
}


/*********************************************************************
* Function: linear_search_move_to_head
* About:    searching with the optimized linear search.
* 
**********************************************************************/
int Array::linear_search_move_to_head(int key)
{
    int res = ERR;
    if (length == 0)
    {
        cout<<"Empty Array"<<endl;
    }
    else
    {    
        for(int i = 0; i < length; i++)
        {
            if(A[i] == key)
            {
                swap_array_item(i, 0);              
                res = 0;
                break;
            }
        }
    }
    return res;
}


/*********************************************************************
* Function: _binary_search
* About:    helper function for binary searching
*           
* 
**********************************************************************/
int  Array::_binary_search(int low, int high, int key)
{
    while(low <= high)
    {
        int mid = (low+high)/2;
        
        if(key == A[mid])
        {
            return mid;
        }
        else if(key < A[mid])
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
* Function: _binary_search_rec
* About:    helper function for binary_search recursive way
* 
**********************************************************************/
int  Array::_binary_search_rec(int low, int high, int key)
{
    if(low <= high)
    {
        int mid = (low+high)/2;
        
        if(key == A[mid])
        {
            return mid;
        }
        else if(key < A[mid])
        {
            return _binary_search_rec(low, mid-1, key);
        }
        else
        {
            return _binary_search_rec(mid+1, high, key);
        }
    }
    return ERR;
}


/*********************************************************************
* Function: binary_search
* About:    binary_search Algo
*           
* 
**********************************************************************/
int  Array::binary_search(int key)
{
    int low = 0 , high = length-1;
    if(length == 0)
    {
        cout<<"Empty Array.."<<endl;
        return ERR;
    }

    return _binary_search(low, high, key);
}


/*********************************************************************
* Function: binary_search_rec
* About:    binary_search recursive algo
*           
* 
**********************************************************************/
int  Array::binary_search_rec(int key)
{
    int low = 0 , high = length-1;
    if(length == 0)
    {
        cout<<"Empty Array.."<<endl;
        return ERR;
    }

    return _binary_search_rec(low, high, key);
}


/*********************************************************************
* Function: get_item_at_index
* About:    getting an element at a given index
*           
* 
**********************************************************************/
int  Array::get_item_at_index(int idx)
{
    if (idx >= 0 && idx < length)
    {
        return A[idx];
    }

    cout<<"Array Empty OR Index is wrong, Length: "<<length<<endl;
    return ERR;
}


/*********************************************************************
* Function: set_item_at_index
* About:    set an element at a given index.
*           
* 
**********************************************************************/
void  Array::set_item_at_index(int idx, int item)
{
    if (idx >= 0 && idx < length)
    {
        A[idx] = item;
        return;
    }

    cout<<"Array Empty OR Index is wrong, Length: "<<length<<endl;
}


/*********************************************************************
* Function: Max
* About:    to find the max element from the array.
* 
**********************************************************************/
int Array::Max()
{
    if(length == 0)
    {
        cout<<"Array is Empty."<<endl;
        return ERR;
    }

    int max = A[0];

    for(int i = 1; i < length; i++)
    {
        if(max < A[i])
        {
            max = A[i];
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
int Array::Min()
{
    if(length == 0)
    {
        cout<<"Array is Empty."<<endl;
        return ERR;
    }

    int min = A[0];

    for(int i = 1; i < length; i++)
    {
        if(min > A[i])
        {
            min = A[i];
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
int Array::sum()
{
    if(length == 0)
    {
        cout<<"Array is Empty"<<endl;
        return 0;
    }

    int sum = 0;

    for(int i = 0; i < length; i++)
    {
        sum += A[i];
    }

    return sum;
}


/*********************************************************************
* Function: _sum_rec
* About:    Helper function for recursive sum
*           
* 
**********************************************************************/
int Array::_sum_rec(int n)
{
    if(n < 0)
    {
        return 0;
    }
    else
    {
        return A[n] + _sum_rec(n-1);
    }
}


/*********************************************************************
* Function: sum_rec
* About:    To calculate the sum of array recursively.
*           
* 
**********************************************************************/
int Array::sum_rec()
{
    if(length == 0)
    {
        cout<<"Array Empty."<<endl;
        return 0;
    }

    return _sum_rec(length - 1);
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
	return false;
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
