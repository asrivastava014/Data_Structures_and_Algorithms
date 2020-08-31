#ifndef TEACHER_H
#define TEACHER_H

#include"user.h"
#include<string>
#include<iostream>
#include<fstream>
#include<string>

class Teacher : public User
{
    private:
        int salary;
            
    public:
        Teacher();     
        ~Teacher();
        void who_i_am();
        void get_salary();
        void set_salary(int salary);      
};



#endif
