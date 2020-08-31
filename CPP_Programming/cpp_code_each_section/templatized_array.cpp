#include<iostream>
#include<array>

using std::cout;

void display_array(std::array<int, 20> data, int count) //pass by Value
{
	for(int i = 0; i < count; i++)
	{
		cout<<data[i]<<"\t";
	}

	cout<<std::endl;

	return;
}



int main()
{
	std::array<int, 20> my_data = {1, 2, 3};

	cout<<"my_data.size(): "<<my_data.size()<<std::endl;
	cout<<"sizeof(my_data): "<<sizeof(my_data)<<std::endl;

	display_array(my_data, 3);

	return 0;
}
