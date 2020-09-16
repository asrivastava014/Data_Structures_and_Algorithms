/*********************************************************************
* Created By: Ankur Srivastava
* About:      Main Program for Array ADT
* 
**********************************************************************/

#include <bits/stdc++.h>
#include "array_adt.h"

#define MAX_CHOICE 8

using namespace std;

int main()
{
    int choice, size, ele, pos;

    cout<<"Enter the size of array you want."<<endl;
    cin>>size;

    Array A(size);

    do 
    {
        cout<<"Enter 1  for display."<<endl;
        cout<<"Enter 2  for append."<<endl;
        cout<<"Enter 3  for insert."<<endl;
        cout<<"Enter 4  for max in array."<<endl;
        cout<<"Enter 5  for set index ."<<endl;
        cout<<"Enter 6  for get index."<<endl;
        cout<<"Enter 7  for searching."<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1: 
                A.display();
                cout<<endl;
                break;

            case 2:
                cout<<"Enter an element to append."<<endl;
                cin>>ele;
                A.append(ele);
                cout<<endl;
                break;

            case 3: 
                cout<<"Enter an element to insert."<<endl;
                cin>>ele;
                cout<<"Enter the position to insert."<<endl;
                cin>>pos;
                A.insert(pos, ele);
                cout<<endl;
                break;

            case 4: 
                cout<<A.Max();
                cout<<endl;
                break;

            case 5: 
                cout<<"Enter an element to insert."<<endl;
                cin>>ele;
                cout<<"Enter the position to insert."<<endl;
                cin>>pos;
                A.set_item_at_index(pos, ele);
                cout<<endl;
                break;

            case 6: 
                cout<<"Enter the position to read the value."<<endl;
                cin>>pos;
                cout<<A.get_item_at_index(pos)<<endl;
                cout<<endl;
                break;

            case 7: 
                cout<<"Enter an element to search."<<endl;
                cin>>ele;
                cout<<A.binary_search(ele)<<endl;
                cout<<endl;
                break;

            default:
                cout<<"Wrong Choice."<<endl;
                cout<<endl;
                break;
        }

    } while(choice < MAX_CHOICE);

    return 0;
}
