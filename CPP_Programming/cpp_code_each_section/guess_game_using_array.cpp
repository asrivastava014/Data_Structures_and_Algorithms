#include<iostream>
#include<ctime>

using std::cout;
using std::cin;

void print_array(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout<<arr[i]<<"\t";
	}

	cout<<std::endl;

	return;
}

void play_game()
{
	int random = rand() % 251;
	int guess, guesses[251];
	int count = 0;

	cout<<"Enter a number to guess..."<<std::endl;

	while(true)
	{
		cin>>guess;

		guesses[count++] = guess;

		if (guess == random)
		{
			print_array(guesses, count);
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


