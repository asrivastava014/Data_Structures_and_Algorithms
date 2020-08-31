
#include"teacher.h"

/* Program to use Friend function for operator overloading,
   which can access the private members, so no more need to
   set data members as public for operator overoading
*/





int main()
{
    Teacher maths_teacher;
    
    maths_teacher.set_status("Gold");
    std::cout<<maths_teacher.get_status()<<std::endl;
    
    maths_teacher.set_salary(25000);
    maths_teacher.get_salary();
    
    Teacher teach;
    User& user = teach;
    
    user.who_i_am();
    
    return 0;
}
