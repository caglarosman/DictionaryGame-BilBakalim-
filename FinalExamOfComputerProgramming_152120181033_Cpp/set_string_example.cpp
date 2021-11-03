// C++ program to demonstrate set of strings

//Benefit()s and Features of std::set:
//It’s doesn’t allow duplicate elements i.e.it only contains unique elements.

#include <iostream>
#include <set>//must be
#include <vector>//must be
#include <string>//must be
using namespace std;

int main()
{
	// Declaring Vector of String type 
	set<string> s_colour;
	string buffer;

	vector<string> v_colour;


	// Initialize set with strings using insert command 
	//It does not delete all the duplicate elements, but it removes duplicacy by just replacing those elements by the next element present in the sequence which is not duplicate to the current element being replaced. 
	//All the elements which are replaced are left in an unspecified state.
	s_colour.insert("Blue");
	s_colour.insert("Red");
	s_colour.insert("Red");//Duplicate is not inserted into set<string>
	s_colour.insert("Orange");
	s_colour.insert("Yellow");
	

	cout << "set<string> prints elements by element by using iterator:"<<endl;
	for (set<string>::iterator it = s_colour.begin(); it != s_colour.end(); ++it)
		cout << *it << endl;


	cout << endl;
	cout << "Assign a set<string> elements by elements to another string:" << endl;
	//assign set elements by elements to another string
	//second Red is not assigned to buffer string
	for (set<string>::iterator it = s_colour.begin(); it != s_colour.end(); ++it)
	{
		buffer = *it;
		cout << buffer << endl;
	}



	cout << endl;
	cout << "Assign a set<string> to vector<string>:"<<endl;
	//assign a set<string> to vector<string>
	v_colour.assign(s_colour.begin(), s_colour.end());	
	for (int i = 0; i < v_colour.size(); i++)
	{
		cout << v_colour[i] << "\n";
	}


	cout << endl << endl;
	system("pause");
	return 0;
}