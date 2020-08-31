#include<iostream>

/* Program for static members inside a class
   a. Only a Static member can access a Static member.
   b. You have to initialize the static data outside
      the Class and after that Class in which it is
      declared.
   c. Static Members are attached with the Class not the
      objects.
*/

class User
{
    static int user_count;
    std::string status;
    
    public:
        static int get_user_count()
        {
            return user_count;
        }
        
        void set_status(std::string status)
        {
            this->status = status;    
        }
        
        std::string get_status()
        {
            return status;
        }
        
        User()
        {
            std::cout<<"In Constructor\n";
            user_count++;
        }
        
        ~User()
        {
            std::cout<<"In Destructor\n";
            user_count--;
        }
};

int User::user_count = 0;

int main()
{
    User user1, user2, user3, user4;
    std::cout<<User::get_user_count()<<std::endl;
    
    user1.~User();
    user4.~User();
    std::cout<<User::get_user_count()<<std::endl;
    
    return 0; 
}

