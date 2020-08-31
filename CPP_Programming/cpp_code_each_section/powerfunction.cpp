#include<iostream>
#include<cmath>

using std::cout;
using std::cin;

int main()
{
	int base, exponent;
    cout<<"Enter base: ";
    cin >> base;
    cout<<"Enter exponent: ";
    cin >> exponent;

    double power = pow(base, exponent);
    cout << power;
    return 0;
}
