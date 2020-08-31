#include<iostream>
#include<vector>

/* A simple program to know, how to create a 
   namespace named utilz
*/

namespace utilz
{
    void display_vector(std::vector<int> my_vect)
    {
        for (int n : my_vect)
        {
            std::cout<<n<<"\t";
        }
        std::cout<<std::endl;
        
        return;
    }
}

//using namespace utilz;

int main()
{
    std::vector<int> vect;
    
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
    vect.push_back(40);
    vect.push_back(50);
    vect.push_back(60);
    
    utilz::display_vector(vect);
    //display_vector(vect);
    
    return 0;
}
