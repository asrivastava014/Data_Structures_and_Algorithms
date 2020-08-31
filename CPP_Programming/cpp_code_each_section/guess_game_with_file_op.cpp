#include<iostream>
#include<ctime>
#include<vector>
#include<fstream>

#define BEST_GUESS 99999
#define FILENAME   "guess_book"

using std::cout;
using std::cin;

void guess_game_init()
{
	std::ofstream file (FILENAME);
	if(file.is_open())
	{
		cout<<"Init Sucess"<<std::endl;
		file << BEST_GUESS;
	}
	else
	{
		cout<<"Init Failed...exiting"<<std::endl;
		exit(0);
	}
	file.close();
}


void print_vector(std::vector<int> vector)
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
	int count = 0;
	guess_game_init();
	std::vector<int> guesses;

	cout<<"Enter a number to guess..."<<std::endl;

	while(true)
	{
		cin>>guess;
		count++;
		guesses.push_back(guess);

		if (guess == random)
		{
			print_vector(guesses);
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

	std::ifstream read_file (FILENAME);
	int best_guess = 0;
	
	if(!read_file.is_open())
	{
		cout<<"Guess Book open failed....."<<std::endl;
		return;
	}
	else
	{
		read_file>>best_guess;
		read_file.close();
		
		std::ofstream write_file (FILENAME);
		if (!write_file.is_open())
		{
			cout<<"Unable to Write to File"<<std::endl;
			return;
		}
		else
		{
			if(count < best_guess)
			{
				write_file << count;
			}
			else
			{
				write_file << best_guess;
			}
		}
		write_file.close();
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


