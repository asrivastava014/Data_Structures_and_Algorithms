/*********************************************************************
* Created By: Ankur Srivastava
* About:      To find the missing element(s): 
*             a) First n natural numbers starting from 1.
*             b) n natural numbers starting from random number.
*             c) Multiple missing elements from a sorted array
*                starting from a random number.
* 
**********************************************************************/

#include<bits/stdc++.h>

using namespace std;

class Array
{
    private:
        int *A;
        int  length;
        int  size;
    
    public:
        Array(int size)
        {
            this->A      = new int[size];
            this->size   = size;
            this->length = 0;
        }

        ~Array()
        {
            delete[] A;
            size   = 0;
            length = 0;
            cout<<"Memory de-allocated..."<<endl;
        }

        void append_array(int item)
        {
            if (length == size)
            {
                cout<<"Array is full."<<endl;
                return;
            }

            A[length++] = item;

            return;
        }

        void display()
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

        void single_miss_n_natrl_numbrs(int last_ele)
        {
            if(length == 0)
            {
                cout<<"Array is empty."<<endl;
                return;
            }

            int sum_nat = (last_ele*(last_ele+1))/2;
            int res = 0;

            for(int i =0; i < length; i++)
            {
                res += A[i];
            }

            cout<<"Missing element is: "<<(sum_nat-res)<<endl;
            return;
        }

        void mult_miss_natrl_num()
        {
            if(length == 0)
            {
                cout<<"Array is empty."<<endl;
                return;
            }

            int diff = A[0];

            for(int i = 0; i < length; i++)
            {
                if(A[i] - i != diff)
                {
                    while(diff < (A[i] - i))
                    {
                        cout<<"Missing element is: "<<(diff+i)<<endl;
                        diff++;
                    }
                }
            }

            return;
        }

        void duplicates_in_sorted_arrays()
        {
            if(length == 0)
            {
                cout<<"Array is empty."<<endl;
                return;
            }

            int last_duplicate = 0;

            for(int i = 0; i < length-1; i++)
            {
                if(A[i] == A[i+1] && A[i] != last_duplicate)
                {
                    cout<<"Duplicate Element: "<<A[i]<<endl;
                    last_duplicate = A[i];
                }
            }

            return;            
        }

        void count_duplicates_sorted()
        {
            int i, j;

            if(length == 0)
            {
                cout<<"Array is empty."<<endl;
                return;
            }

            for(i = 0; i < length -1; i++)
            {
                if(A[i] == A[i+1])
                {
                    j = i+1;

                    while(A[i] == A[j]){j++;}
                    cout<<"Element "<<A[i]<<" appeared for "<<(j-i)<<" times.";
                    cout<<endl;
                    i=j-1;
                }
            }
            return;
        }

        void duplicates_sorted_array_using_hash(int start, int end)
        {
            int i;

            if(length == 0)
            {
                cout<<"Array is empty."<<endl;
                return;
            }

            int *C = new int[end+1];

            memset(C, 0, (sizeof(int) * (end+1)));

            for(i = 0; i < length; i++)
            {
                C[A[i]]++;
            }

            for(i = start; i <= end; i++)
            {
                if(C[i] > 1)
                {
                    cout<<"Element "<<i<<" repeated for "<<C[i]<<" times.";
                    cout<<endl;
                }
            }

            delete[] C;

            return;
        }

        void sum_comb_sorted(int k)
        {
            if(length == 0)
            {
                cout<<"Array Empty."<<endl;
                return;
            }

            int i = 0, j = length-1;

            while(i < j)
            {
                if(A[i] + A[j] == k)
                {
                    cout<<A[i]<< " + "<<A[j]<<" = "<<k;
                    cout<<endl;
                    i++;
                    j--;
                }
                else if(A[i] + A[j] < k)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
            return;
        }
};


int main()
{
    Array A(10);

    int i;
    //int temp[]   =  {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};
    //int temp1[]  =  {6, 7, 8, 9, 11, 12, 15, 16, 21};
    //int temp2[]  =  {6, 12, 13, 14, 15, 16, 17, 20, 22};
    //int temp3[]  =  {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int temp3[]  =  {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};

    for(i = 0; i < 10; i++)
    {
        A.append_array(temp3[i]);
    }

    A.display();
    //A.duplicates_in_sorted_arrays();
    //A.count_duplicates_sorted();
    //A.duplicates_sorted_array_using_hash(3, 20);
    A.sum_comb_sorted(10);

    return 0;
}