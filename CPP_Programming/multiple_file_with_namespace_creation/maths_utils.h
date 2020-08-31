#ifndef MATHS_UTILS_H
#define MATHS_UTILS_H

struct Rectangle {
					 double length;
					 double breath;
				 };
				 

				 
namespace math_utilz
{
    typedef union { 
                    unsigned long long big_var;
                    unsigned long small_var;
                  } LARGE_INT;
    double area(Rectangle rectangle);
    double area(double length, double breath);
    double area(double length);
    double pow(double base, int exp = 2);
}

#endif
