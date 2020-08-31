#include"teacher.h"
#include<iostream>


Teacher::Teacher()
{
    std::cout<<"Teacher Created...."<<std::endl;
}


Teacher::~Teacher()
{
    std::cout<<"Teacher Deleted...."<<std::endl;
}

void Teacher::who_i_am()
{
    std::cout<<"I am a Teacher...."<<std::endl;
}


void Teacher::get_salary()
{
    std::cout<<"Salary: "<<salary<<" INR"<<std::endl;
}


void Teacher::set_salary(int salary)
{
    this->salary = salary;
}


