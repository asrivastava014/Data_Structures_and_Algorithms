#include <iostream>

using std::cout;

int main()
{
	typedef enum season { 
 							summer = 0,
							winter = 1,
							rains,
                            wrong = 0xff,
						} indian_seasons;

	int seasons = 1;
    indian_seasons ii = summer;

    switch(ii)
    {
		case summer:
				cout<<"Switch On the AC\n";
				break;

		case winter:
				cout<<"Stay Warm\n";
				break;

		case rains:
				cout<<"Use Umbrella\n";
                break;
		default:
				cout<<"Oops, Wrong\n";
 				break;
    }
}
