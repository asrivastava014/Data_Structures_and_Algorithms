#include"maths_utils.h"


namespace math_utilz
{
    double pow(double base, int exp)
    {
        double total = 1;
        
        for(int i = 0; i < exp; i++)
        {
            total *= base;
        }
        return total;
    }

    double area(Rectangle rectangle)
    {
        return (rectangle.length * rectangle.breath);
    }


    double area(double length, double breath)
    {
        return (length * breath);
    }
    
    double area(double length)
    {
        return (length * length);
    }
}



