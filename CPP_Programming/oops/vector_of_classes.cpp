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

int check_array_for_duplicate(std::vector<User> &users, User user)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].first_name == user.first_name &&
           users[i].last_name == user.last_name)
        {
            std::cout<<"Entry already Present at "<<i<<" index."<<std::endl;
            return i;        
        }
    }
    users.push_back(user);
    
    return users.size() - 1;
}
    
    
int main()
{
    std::vector<User> users;
    User user1, user2, user3, user4, user5;
    
    user1.first_name  = "Ankur";
    user1.last_name   = "Srivastava";
    
    user2.first_name  = "Ekta";
    user2.last_name   = "Sinha";
    
    user3.first_name  = "Sakshi";
    user3.last_name   = "Chit";
    
    user4.first_name  = "Sakshi";
    user4.last_name   = "Chit";
    
    user5.first_name  = "Sakshi";
    user5.last_name   = "Srivastava";
    
    //users.push_back(User()); //Calling Constructor explicitly
    users.push_back(user1);
    users.push_back(user2);
    users.push_back(user3);
    
    for(int i = 0; i < users.size(); i++)
    {
        std::cout<<"First Name: "<<users[i].first_name<<std::endl;
    }
    
    std::cout<<check_array_for_duplicate(users, user4)<<std::endl;
    std::cout<<check_array_for_duplicate(users, user5)<<std::endl; 
    
    for(int i = 0; i < users.size(); i++)
    {
        std::cout<<"First Name: "<<users[i].first_name<<std::endl;
    }   
   
    return 0;
}
