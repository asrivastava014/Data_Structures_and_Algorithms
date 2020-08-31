#include<iostream>


/* This Program interchanges the value of two
   variable using call by reference technique
*/

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    
    std::cout<<"a: "<<a<<"\tb: "<<b<<std::endl;
    
    return;	
}


int main()
{
    int a = 10, b = 20;
    std::cout<<"a: "<<a<<"\tb: "<<b<<std::endl;
    swap(a, b);
    std::cout<<"a: "<<a<<"\tb: "<<b<<std::endl;
    
}
