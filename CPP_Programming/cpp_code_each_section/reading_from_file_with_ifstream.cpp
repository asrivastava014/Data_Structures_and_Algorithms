#include<iostream>
#include<vector>
#include<fstream>

int main()
{
	std::string filename;
	std::cin>>filename;

	std::ifstream file (filename);

	if(!file.is_open())
	{
		std::cout<<"File open failed."<<std::endl;
		exit(0);
	}
	else
	{
		std::cout<<"File open success"<<std::endl;
	}

	std::string data;
	std::vector<std::string> read_file;

	while(file >> data)
	{
		read_file.push_back(data);
	}

	std::cout<<"End of file reached"<<std::endl;

	for(std::string print_name : read_file)
	{
		std::cout<<print_name<<std::endl;
	}

	return 0;
}
