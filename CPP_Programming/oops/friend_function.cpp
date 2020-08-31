#include<iostream>
#include<fstream>
#include<string>

/* Program to use Friend function for operator overloading,
   which can access the private members, so no more need to
   set data members as public for operator overoading
*/


class User
{
    std::string status;
    
    public:
        std::string first_name;
        std::string last_name;
        friend std::ostream& operator << (std::ostream& output, const User user);
        friend std::istream& operator >> (std::istream& input, User &user);
        friend void show_status(User user);

};

void show_status(User user)
{
    std::cout<<"Status: "<<user.status<<std::endl;
    return;
}


std::ostream& operator << (std::ostream& output, const User user)
{
    output<<"First Name: "<<user.first_name<<"\n";
    output<<"Second Name: "<<user.last_name<<"\n";
    output<<"Status: "<<user.status;
    
    return output;
}



std::istream& operator >> (std::istream& input, User &user)
{
    input>>user.first_name;
    input>>user.last_name;
    input>>user.status;

    return input;
}


int main()
{
    User user;
    
    std::cin>>user;
    std::cout<<user<<std::endl;
    show_status(user);
    
    return 0;
}
