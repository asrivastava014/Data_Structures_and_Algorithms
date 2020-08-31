#include<iostream>

/* Program for operator overloading, we will
   see how a general operator like +,== can be oveloaded
   to perform operation on custom data types like 
   addition of 2 objects.
*/

class Position
{
    /* Here we need to set Data variables as Public
       else we cannot access these members of other
       object in our oveloaded function
    */
    public:
        int x = 10; //Inline initialization c++11 Standard
        int y = 20; //Inline initialization c++11 Standard
        
        Position operator + (Position pos)
        {
            Position new_pos;
            
            new_pos.x = x + pos.x;
            new_pos.y = y + pos.y;
            
            return new_pos;
        }
        
        bool operator == (Position pos)
        {
            if (x == pos.x && y == pos.y)
            {
                return true;
            }
            return false;   
        }
};



int main()
{
    Position A, B;
    Position C = A + B;
    
    std::cout<<C.x<<" "<<C.y<<std::endl;
    
    if (A == B)
    {
        std::cout<<"Both the objects are equal\n";
    }
    
    return 0;
}
