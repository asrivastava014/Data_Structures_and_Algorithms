#include<iostream>
#include<fstream>
#include<string>
#include"user.h"

/* Program to use Friend function for operator overloading,
   which can access the private members, so no more need to
   set data members as public for operator overoading
*/





int main()
{
    User user("Ankur", "Srivastava", "Gold");
    
    //std::cin>>user;
    //std::cout<<user<<std::endl;
    show_status(user);
    std::cout<<User::get_user_count()<<std::endl;
    
    return 0;
}
