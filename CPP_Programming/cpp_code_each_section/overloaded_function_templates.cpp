#include<iostream>
#include<string>
#define SIZE 9

/* This programs deals in creation of a Template
   Functions which can take any type of data types,
   plus overloading the function template since the 
   first template is having limitation to take 
   arguments of very basic type, it won't work if
   the coming arguments are arrays since the logic
   will throw an error as u cannot directly assign
   one array to another, rather we need to do this
   array swap index by index in a loop.
   
   WAP to swap variable of one array with variables
   of seconf array, size will be given, use 
   overloading of function Templates.
   
   Also remember we don't need to catch the arguments
   of array with ampersand(&) as by default array is
   always passed as a reference.
*/


template <typename T>
void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
    
    return;
}

/*   size is important to give else both the
     templates will have same signature 
     and if you call the swap with only 2
     arguments of array the first template
     swap function will be called and will 
     throw an error due to the logic.
*/
template <typename T>
void swap(T a[], T b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        T temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
    
    return;
}


int main()
{
    int x = 10, y = 20;
    swap(x, y);
    std::cout<<x<<" "<<y<<std::endl;
    
    
    std::string name = "Ankur";
    std::string title = "Srivastava";
    swap(name, title);
    std::cout<<name<<" "<<title<<std::endl;
    
    int nines[SIZE] = {9,9,9,9,9,9,9,9,9};
    int ones[SIZE]  = {1,1,1,1,1,1,1,1,1};
    
    for(int i = 0; i < SIZE; i++)
    {
        std::cout<<nines[i]<<" "<<ones[i]<<"\t";
    }
    std::cout<<std::endl;
    
    swap(nines, ones, SIZE);
    
    for(int i = 0; i < SIZE; i++)
    {
        std::cout<<nines[i]<<" "<<ones[i]<<"\t";
    }
    std::cout<<std::endl;
    
    return 0;
}
