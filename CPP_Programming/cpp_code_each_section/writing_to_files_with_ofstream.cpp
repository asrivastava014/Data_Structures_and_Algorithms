#include<iostream>
#include<vector>
#include<fstream>

int main()
{
	std::string filename;
	std::cin>>filename;

	//File custom object to create/open a file in append mode
	std::ofstream file (filename.c_str(), std::ios::app);
	
	/* One more method for definition/decleration of file object.
	   std::ofstream file; 
	   file.open(filename.c_str(), std::ios::app);
	*/

	if(file.is_open())
	{
		std::cout<<"File was opened/created successfully...."<<std::endl;
	}
	else
	{
		std::cout<<"File opening/creation failed exiting...."<<std::endl;
		exit(0);
	}

	std::vector<std::string> names;

	names.push_back("Ankur");
	names.push_back("Srivastava");
	names.push_back("Sakshi");
	names.push_back("Chitranshi");

	//Range based looping in which we are pushing names one by one in the file object.
	for(std::string name : names)
	{
		file<<name<<std::endl;
	}

	file.close(); //Close function, although systems takes care of it, but a good practice.

	return 0;
} //end of main
