#include<iostream>
#include<vector>

/* This program will show how to create
   a C++ Objects through the Class with 
   Access Modifiers 
   for Members(Variable/Methods).
   
   Also this program will show that our
   customized data type Class is feasible 
   with every system defined data types like
   array/vectors etc.
   
   We will also look into how the Constructors
   and destructors are written and called.
   
   Additional things is the getter and setter 
   function which will lay down the foundation
   of Encapsulation.
*/

class User
{
    std::string status;
    
    public:
        std::string first_name;
        std::string last_name;

        std::string get_status()  //Getter function 
        {
            return status;        
        }
        
        void set_status(std::string status) //Setter function
        {
            if (status == "Gold"   || 
                status == "Silver" ||
                status == "Bronze"  )
            {
                this->status = status;
            }
            else
            {
                std::cout<<"Wrong Status entered...."<<std::endl;
                this->status = "Not Applicable";
            }
            return;
        }
        
        User()
        {
            std::cout<<"In default Constructor......"<<std::endl;
        }
        
        User(std::string first_name, std::string last_name)
        {
            std::cout<<"In Custom Constructor...."<<std::endl;
            /* this pointer is used since the argument's name and
               data member's name are same.
            */
            this->first_name = first_name;
            this->last_name = last_name;
        }
        
        ~User()
        {
            std::cout<<"In Destructor..."<<std::endl;
        }
};

       
int main()
{
    User user;
    std::string status;
    
    std::cout<<"Enter a Status...."<<std::endl;
    std::cin>>status;
    
    user.set_status(status);
    std::cout<<user.get_status()<<std::endl;
   
    return 0;
}
