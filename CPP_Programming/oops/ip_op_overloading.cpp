#include<iostream>
#include<fstream>
#include<string>


class User
{
    std::string status;
    
    public:
        std::string first_name;
        std::string last_name;
};


std::ostream& operator << (std::ostream& output, const User user)
{
    output<<"First Name: "<<user.first_name<<"\n";
    output<<"Second Name: "<<user.last_name;
    
    return output;
}



std::istream& operator >> (std::istream& input, User &user)
{
    input>>user.first_name;
    input>>user.last_name;

    return input;
}


int main()
{
    User user;
    
    std::cin>>user;
    std::cout<<user<<std::endl;
    
    return 0;
}
