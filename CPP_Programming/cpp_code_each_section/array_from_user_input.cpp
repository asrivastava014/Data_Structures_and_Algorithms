#include<iostream>
#include<limits>
/* In this Program we will see array features 

   1- Defining an array of say 100 elements.
   2- Staring a loop of 100 which will bound 
      the user to give 100 entries through keyboard.
   3- What will happen if user only wants  to give 
      5 entries, but since it's a loop of 100
      how will u achieve this ?
*/

using std::cout;
using std::cin;

void display_array(int in_arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<in_arr[i]<<"\t";
    }
    
    cout<<std::endl;
}


int main()
{
    const int SIZE = 100;
    int arr[SIZE];
    int count = 0;
	int i;
   
 
    for(i = 0; i < SIZE; i++)
    {    
        if(cin>>arr[i])//returns true only if it properly stores it's value
        {
            //Input Worked, user entered a value of expected data type(int).
            count++;        
        }
        else
        {
            /* Input Failed, user entered a value of unexpected 
               data type eg(char, string). One more thing when
               cin evaluates to false, it will be in non-working
               state that means there was an error in the input
               that was not a correct type, cin will remain in
               that state untill we clear(.clear) it's state, after
               clearing it's state it will be in workable state but
               it will continue to hold that incorrect value, and if 
               anywhere in the program u again called cin from
               the user, it will load the previously loaded
               value to that cin variable despite of taking it
               from the user, for eg if you typed "haha" in 
               order to come out from the loop, the cin will
               hold that "haha" which wasn't cleared and it
               will be waiting for any cin call in order to push
               that value into the variable of new cin. So after
               coming out from this cin if you anywhere in the 
               program again used cin with a expected char/string
               it will push that "haha" to that new variable which
               will eventually make your code buggy. We need to clear 
               the cin with the clear/ignore calls used in the main 
               program.
            */
            break;
        }
    }
    
    /* Here we need to clear the non-working state first */
    cin.clear();

	/* Here now u want to ignore the wrong value entered 
       which made cin non-workable ie expected an int and
       user entered a character or a string, Now u need
       to tell the cin to ignore those wrong values here 
       it can ignore 1000 characters, but what will happen
       if user entered 1001 character, solution is below */
    //cin.ignore(1000,'\n');
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore max entries

	std::string new_str;
    
    display_array(arr, count);
    cout<<"Enter a String"<<std::endl;
    cin>>new_str;
    cout<<new_str<<std::endl;            

    return 0;
}





