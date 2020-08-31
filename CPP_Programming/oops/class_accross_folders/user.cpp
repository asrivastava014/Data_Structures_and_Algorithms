#include<iostream>
#include"user.h"


int User::user_count = 0;
int User::get_user_count()
{
    return user_count;
}
        
std::string User::get_status()  //Getter function 
{
    return status;        
}

void User::set_status(std::string status) //Setter function
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

User::User()
{
    std::cout<<"In default Constructor......"<<std::endl;
    user_count++;
}


User::User(std::string first_name, std::string last_name, std::string status)
{
    std::cout<<"In Custom Constructor...."<<std::endl;
    /* this pointer is used since the argument's name and
       data member's name are same.
    */
    this->first_name = first_name;
    this->last_name  = last_name;
    this->status     = status;
    user_count++;
}

User::~User()
{
    std::cout<<"In Destructor..."<<std::endl;
    user_count--;
}

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




