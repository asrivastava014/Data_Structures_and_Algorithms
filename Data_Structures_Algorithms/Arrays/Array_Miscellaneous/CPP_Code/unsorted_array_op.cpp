/*********************************************************************
* Created By: Ankur Srivastava
* About:      To find the missing element(s): 
*             a) Multiple missing elements from a unsorted array
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

        void find_missing_using_hash(int first, int last, int size)
        {
            if (size == 0)
            {
                cout<<"Empty Array.\n";
                return;
            }

            int *C = new int[last+1];
            if(!C)
            {
                cout<<"Memory not available."<<endl;
                return;
            }

            memset(C, 0, (sizeof(int) * (last+1)));

            for(int i = 0; i < (last+1); i++)
            {
                cout<<C[i]<<"\t";
            }
            cout<<endl;

            for(int i = 0; i < size; i++)
            {
                C[A[i]]++;
            }

            for(int i = first; i <= last; i++)
            {
                if(C[i] == 0)
                {
                    cout<<"Missing element: "<<i<<endl;
                }
            }

            delete[] C;

            return;
        }

        void duplicate_elements_unsorted()
        {
            int i, j, count;

            if(length == 0)
            {
                cout<<"Array empty."<<endl;
                return;
            }

            for(i = 0; i < length-1; i++)
            {
                count = 1;

                if(A[i] != -1)
                {
                    for(j = i+1; j < length; j++)
                    {
                        if(A[i] == A[j])
                        {
                            count++;
                            A[j] = -1;
                        }
                    }
                    if(count > 1)
                    {
                        cout<<"Element "<<A[i]<<" repeats for "<<count<<" times.";
                        cout<<endl;
                    }
                }
            }
            return;
        }

        void dup_unsorted_hash(int last)
        {
            if(length == 0)
            {
                cout<<"Array Empty."<<endl;
                return;
            }

            int *C = new int[last+1];
            if(!C)
            {
                cout<<"Memory not available."<<endl;
                return;
            }

            memset(C, 0, (sizeof(int) * (last+1)));

            for(int i = 0; i < length; i++)
            {
                C[A[i]]++;
            }

            for(int i = 0; i < last+1; i++)
            {
                if (C[i] > 1)
                {
                    cout<<"Element "<<i<<" repeats for "<<C[i]<<" times.";
                    cout<<endl;
                }
            }

            delete[] C;

            return;
        }

        void comb_sum_unsorted(int k)
        {
            if (length == 0)
            {
                cout<<"Array Empty."<<endl;
                return;
            }

            int i , j;

            for(i = 0; i < length-1; i++)
            {
                for(j = i+1; j < length; j++)
                {
                    if(A[i] + A[j] == k)
                    {
                        cout<<"Combination found: "<<A[i]<<" + "<<A[j]<<" = "<<k;
                        cout<<endl;
                    }
                }                
            }

            return;
        }


        void comb_sum_hash(int k, int last)
        {
            int i;

            if(length == 0)
            {
                cout<<"Array empty."<<endl;
                return;
            }

            int *H = new int[last+1];
            if(!H)
            {
                cout<<"Memory not available."<<endl;
                return;
            }

            for(i = 0; i < length; i++)
            {
                if(k-A[i] >= 0)
                {
                    if (H[k-A[i]] != 0)
                    {
                        cout<<A[i]<<" + "<<(k-A[i])<<" = "<<k;
                        cout<<endl;
                    }
                }
                H[A[i]]++;
            }

            delete[] H;

            return;
        }

        void max_min_single_scan()
        {
            if(length == 0)
            {
                cout<<"Array empty."<<endl;
                return;
            }

            int min = A[0], max = A[0];
            int i;

            for(i = 1; i < length-1; i++)
            {
                if(A[i] < min)
                {
                    min = A[i];
                }
                else if(A[i] > max)
                {
                    max = A[i];
                }
            }

            cout<<"Max is: "<<max<<"\t"<<"Min is: "<<min<<endl;
            return;
        }
};


int main()
{
    Array A(10);

    int i;
    //int temp[]   = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    //int temp[]   = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    //int temp[]   = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int temp[]   = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};

    for(i = 0; i < 10; i++)
    {
        A.append_array(temp[i]);
    }

    A.display();

    //A.find_missing_using_hash(1, 12, 10);
    //A.duplicate_elements_unsorted();
    //A.dup_unsorted_hash(8);

    //A.comb_sum_unsorted(10);
    //A.comb_sum_hash(10, 16);

    A.max_min_single_scan();

    return 0;
}