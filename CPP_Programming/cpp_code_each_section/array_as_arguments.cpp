#include<iostream>
/* This Program gives a glimpse how to pass a whole
   1-D array as an arguments to a function, Also 
   the difference in passing a whole array Vs passing
   an element to a function.
   
   1.- When u are passing an element say an integer
       to a function, the called functions works on a
       copy of that integer passed, unless u pass 
       that interger's address. 
       
   2.- Whereas when u pass a whole array as an argument
       to a function then the called function will have
       the access to the original array.
       
   3.- This program also plays with the pointer arithmatic
       in the array.
*/

using std::cout;

void display_array(int in_array[], int size)
{
    cout<<"Size of array when passed as an argument: "<<sizeof(in_array)<<"\n";
    
    for(int i = 0; i < size; i++)
    {
        cout<<in_array[i]<<"\t"; 
        *(in_array + i) = i+3;
    }
    
    cout<<std::endl;

    for(int i = 0; i < size; i++)
    {
        cout<<*(in_array + i)<<"\t"; 
    }    
    cout<<std::endl;
    
    return;
}


int main()
{
    int my_array[] = {2,3,4,5,1};
    int size = sizeof(my_array)/sizeof(my_array[0]);
    
    cout<<"Size of array in main function is: "<<sizeof(my_array)<<std::endl;
    
    for(int i = 0; i < size; i++)
    {
        cout<<*(my_array + i)<<"\t";
        *(my_array + i) = i;
    }
    cout<<"\n";    
    
    display_array(my_array, size);
    
    for(int i = 0; i < size; i++)
    {
        cout<<*(my_array + i)<<"\t";
    }
    cout<<"\n";

    return 0;
}
