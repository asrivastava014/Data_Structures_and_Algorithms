#include<bits/stdc++.h>

using namespace std;

void reverse(int a[], int l)
{
    int i,j;
    int b[l];

    for(i = 0, j = l-1; i < l && j>=0; i++,j--)
        b[i] = a[j];

    for (int i = 0; i < l; i++)
        cout<<b[i]<<"\t";
    cout<<endl;
}


void reverse_opt(int a[], int l)
{
    int i, j, temp;

    for(i = 0, j = l-1; i < j ; i++,j--)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    for (int i = 0; i < l; i++)
        cout<<a[i]<<"\t";
    cout<<endl;
}

int main()
{
    int arr[] = {1,2,3,4};
    int arr1[] = {1,2,3,4,5};
    int arr2[1] = {5};

    reverse_opt(arr, 4);
    reverse_opt(arr1, 5);
    reverse_opt(arr2, 1);
    reverse(arr2, 1);
    //void reverse(arr1);
/*
    for (int i = 0; i < 4; i++)
        cout<<arr[i]<<"\t";
    cout<<endl;

    for (int i = 0; i < 4; i++)
        cout<<arr1[i]<<"\t";
    cout<<endl;
*/

}