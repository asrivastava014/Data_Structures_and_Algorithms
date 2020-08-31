#include<iostream>
#include<vector>

/* This program deals in vectors/associated menthods
   how vector is passed as an argument to a function
   and how vector reacts when it is passed as a value
   and as a reference to a function.
*/

using std::cout;


void print_vectors(std::vector<int> vector_print)
{
	for(int i = 0; i < vector_print.size(); i++)
	{
		cout<<vector_print[i]<<"\t";
	}
	cout<<std::endl;

	return;
}


void ops_on_vector_pass_by_value(std::vector<int> vect)
{
	print_vectors(vect);

	vect.push_back(18); //pushes 18 as a last vector element
	vect.push_back(20);

	cout<<"Vector Size: "<<vect.size()<<std::endl;

	print_vectors(vect);
	vect.pop_back();    //pops out OR removes the last vector element.
	cout<<"Vector Size: "<<vect.size()<<std::endl;
	print_vectors(vect);

	return;
}


void ops_on_vector_pass_by_reference(std::vector<int> &vect)
{
	print_vectors(vect);

	vect.push_back(22);
	vect.push_back(23);

	cout<<"Vector Size: "<<vect.size()<<std::endl;

	print_vectors(vect);
	vect.pop_back();
	cout<<"Vector Size: "<<vect.size()<<std::endl;
	print_vectors(vect);

	return;
}


int main()
{
	std::vector<int> data = {1,2,3};
	print_vectors(data);

	ops_on_vector_pass_by_value(data);
	print_vectors(data);
	ops_on_vector_pass_by_reference(data);
	print_vectors(data);

	return 0;
}
