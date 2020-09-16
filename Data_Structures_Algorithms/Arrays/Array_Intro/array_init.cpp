/*********************************************************************
* Created By: Ankur Srivastava
* About:      To design realloc for arrays that is to
*             resize the array if it has underflowed/overflowed 
* 
**********************************************************************/


#include <bits/stdc++.h>

using namespace std;

void my_realloc(int **curr, int curr_size, int new_size)
{
    int *temp = new int[new_size];
    
    memset(temp, 0, (sizeof(int) * new_size));

    for(int i = 0; i < curr_size; i++)
    {
        printf("%d\t", (*curr)[i]);
    }
    printf("\n");

    for(int i = 0; i < curr_size; i++)
    {
        temp[i] = (*curr)[i];
        printf("%d\t", temp[i]);
    }
    printf("\n");

    delete[] (*curr);
    *curr = temp;
    temp = NULL;
    return;
}


int main()
{
    int n;
    cin >> n;

    int *curr = new int[n];

    int arr[n];  //dynamically sized

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        curr[i] = arr[i];
        cout << *(arr + i) <<"\t";
    }
    cout<<endl;

    my_realloc(&curr, n, 10);

    for (int i = 0; i < n; i++)
    {
        cout << curr[i];
    }

    delete[] curr;    

    return 0;
}
