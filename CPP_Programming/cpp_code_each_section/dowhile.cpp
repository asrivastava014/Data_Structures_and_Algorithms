#include <iostream>

int main()
{
	int factorial, result, i;

	std::cout<<"Enter the number: "<<std::endl;
	std::cin>>factorial;

	result = factorial;

	if (result == 0 || result == 1)
	{
		std::cout<<"Factorial of "<<factorial<<" is: "<<result<<std::endl;
		exit (0);
	}

	i = result - 1;

	do 
	{
		result *= i;
		i--;
	} while(i > 1);

	std::cout<<"Factorial of "<<factorial<<" is: "<<result<<std::endl;

	return 0;
}
