#include<iostream>
#include<climits>
#include<float.h>

using std::cout;

int main()
{
	float a = 10.0/3;
    a*=1000000000000;
    double b = 10.0/3;
    b*=1000000000000;
    long double c = 10.0/3;
    c*=1000000000000;

    cout<<std::fixed<<a<<"\n";
    cout<<std::fixed<<b<<"\n";
    cout<<std::fixed<<c<<"\n";

    cout <<FLT_DIG<<"\n";
    cout <<DBL_DIG<<"\n";
    cout <<LDBL_DIG<<"\n";
	return 0;

}
