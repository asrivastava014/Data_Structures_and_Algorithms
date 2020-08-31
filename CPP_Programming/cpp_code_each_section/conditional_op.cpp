#include<iostream>

int main()
{
	int  number = 23, guess;

    std::cout<<"Enter a number to guess!"<<std::endl;
    std::cin>>guess;

    (guess == number)?(std::cout<<"Right\n"):(std::cout<<"Wrong\n");

	return 0;
}
