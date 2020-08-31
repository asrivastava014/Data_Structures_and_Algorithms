#include<iostream>
#include"maths_utils.h"

/* This Program analyse the function over loading
   functionality of C++, We are creating 3 types
   of functions having identical name and different 
   arguments type which means a single function 
   "area" will be overloaded to calculate area
   of three type of shapes, Note function overloading
   does not works with non-identical return type 
   and identical function name and argument, rather
   it works with identical everything except non-identical
   function argument type else for all the other case
   it will throw an error
*/

//We will be writing this program by creating one customized namespace.

int main()
{
    Rectangle rectangle;
    math_utilz::LARGE_INT big_int;
    
    big_int.big_var = 999999;
    
    rectangle.length = 9;
    rectangle.breath = 10;
    
    std::cout<<big_int.big_var<<std::endl;
    std::cout<<math_utilz::area(rectangle.length, rectangle.breath)<<std::endl;
    std::cout<<math_utilz::area(rectangle.length)<<std::endl;
    std::cout<<math_utilz::area(rectangle)<<std::endl;
    std::cout<<math_utilz::pow(3, 3)<<std::endl;
    std::cout<<math_utilz::pow(3)<<std::endl;

    
    return 0;
}







