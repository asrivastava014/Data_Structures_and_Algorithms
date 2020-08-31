#include<iostream>
#include<string>

/* This programs deals in creation of a Template
   Functions which can take any type of data types
*/


template <typename T>
void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
    
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
    
    return 0;
}
