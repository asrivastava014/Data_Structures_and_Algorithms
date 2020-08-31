#include<iostream>
#include<ctime>
#include<vector>

using std::cout;
using std::cin;

void print_array(std::vector<int> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		cout<<vector[i]<<"\t";
	}

	cout<<std::endl;

	return;
}

void play_game()
{
	int random = rand() % 251;
	int guess;
	std::vector<int> guesses;

	cout<<"Enter a number to guess..."<<std::endl;

	while(true)
	{
		cin>>guess;

		guesses.push_back(guess);

		if (guess == random)
		{
			print_array(guesses);
			cout<<"You Guessed the right answer which is "<<random<<", You Won"<<std::endl;
			break;
		}
		else if(guess > random)
		{
			cout<<"Guess is Too Large\n";
			continue;
		}
		else
		{
			cout<<"Guess is Too Low\n";
			continue;
		}
	}

	return;
}



int main()
{
	srand(time(NULL)); //For seeding purpose, so that the pattern should not repeat for random numbers.

	int choice;

	do 
	{
		cout<<"0. Exit Game\n"<<"1. Play Game"<<std::endl;
		cin>>choice;

		switch(choice)
		{
			case 0:
				cout<<"Thanks for Nothing..!!"<<std::endl;
				break;

			case 1:
				cout<<"Lets the Game begins....."<<std::endl;
				play_game();
				break;
		}
	} while(choice != 0);

	return 0;
}


