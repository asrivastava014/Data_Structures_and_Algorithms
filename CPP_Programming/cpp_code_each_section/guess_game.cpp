#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>


/* Function where actual game starts */
void play_game()
{

	int random = rand() % 251;

	std::cout<<"Enter a number for guess"<<std::endl;

	while (true)
	{
		int guess;
		std::cin>>guess;

		if (guess == random)
		{
			std::cout<<"Your Guess was right, You Won..!!"<<std::endl;
			std::cout<<"Random no was: "<<random<<std::endl;
			break;
		}
		else if(guess > random)
		{
			std::cout<<"Guess is Too High"<<std::endl;
		}
	    else
		{
			std::cout<<"Guess is Too Low"<<std::endl;
		}
	}
}


int main()
{
 	srand(time(NULL)); //For seed value of random numbers, everytime u will get new pattern of numbers.

	int choice;

	do
	{
		std::cout<<"0. Quit"<<std::endl<<"1. Play Game"<<std::endl;
		std::cin>>choice;

		switch(choice)
		{
			case 0:
				std::cout<<"Thanks for Nothing..!!"<<std::endl;
				break;
			case 1:
				std::cout<<"Lets Play....."<<std::endl;
				play_game();
				break;
		}
	} while(choice != 0);

	return 0;
}
