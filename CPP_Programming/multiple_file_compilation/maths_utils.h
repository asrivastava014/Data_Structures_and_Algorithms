#ifndef MATHS_UTILS_H
#define MATHS_UTILS_H

struct Rectangle {
					 double length;
					 double breath;
				 };
				 

double area(Rectangle rectangle);
double area(double length, double breath);
double area(double length);
double pow(double base, int exp = 2);

#endif
