#include<iostream>
#include<vector>
#include<array>

/* This Program deals with range based for looping concept of
   C++ 11 Standard as compared to normal "for" looping. */

/* Remember you can not use range based for looping to an
   array(C-Style) which is passed as an argument to that
   function where you want to use the range-based looping */   

using std::cout;



int main()
{
	std::array<int, 5> stl_arr_data = {12, 13, 14, 15, 16};
	std::array<int, 10> stl_arr_cal = {17, 18, 19, 20, 21};
	std::vector<int> vect_data      = {7, 8, 9, 10, 11};
	int arr_data[]                  = {1, 2, 4, 5, 6};

	//Range Based Looping for C-Style Array
	for(int n : arr_data)
	{
		cout<<n<<"\t";
	}
	cout<<std::endl;

	//Range Based Looping for Vectors
	for(int n : vect_data)
	{
		cout<<n<<"\t";
	}
	cout<<std::endl;

	//Range Based Looping for stl_array (all value defined)
	for(int n : stl_arr_data)
	{
		cout<<n<<"\t";
	}
	cout<<std::endl;

	//Range Based Looping for stl_array (half value defined as compared to size)
	for(int n : stl_arr_cal)
	{
		cout<<n<<"\t";
	}
	cout<<std::endl;

}
