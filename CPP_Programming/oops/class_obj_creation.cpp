#include<iostream>

/* This program will show how to create
   a C++ Objects through the Class with 
   Access Modifiers 
   for Members(Variable/Methods).
*/

class User
{
    std::string status = "Gold Standard";
    
    public:
        std::string first_name;
        std::string last_name;

        std::string get_status()
        {
            return status;        
        }
};
    
    
int main()
{
    User me;
    
    me.first_name  = "Ankur";
    me.last_name   = "Srivastava";
    
    std::cout<<"First Name: "<<me.first_name<<std::endl;
    std::cout<<"Last Name: "<<me.last_name<<std::endl;
    std::cout<<"Status: "<<me.get_status()<<std::endl;
    
    return 0;
}
