// C++ program to demonstrate vector of strings using 
//look at
//https://www.bitdegree.org/learn/c-plus-plus-vector/amp
//https://www.geeksforgeeks.org/advantages-of-vector-over-array-in-c/

//Benefit(s):
//the vectors are resizable i.e they can grow and shrink as vectors are allocated on heap memory.


#include <iostream>
#include <vector>//must be
#include <string>//must be
using namespace std;

int main()
{
	// Declaring Vector of String type 
	vector<string> v_colour;
	string buffer;


	// Initialize vector with strings using push_back 
	// command 
	v_colour.push_back("Blue");
	v_colour.push_back("Red");
	v_colour.push_back("Orange");
	v_colour.push_back("Yellow");

	// Print Strings stored in Vector 
	for (int i = 0; i < v_colour.size(); i++)
	{
		buffer = v_colour[i]; //assgin a buffer string
		cout << buffer << endl;

	}

	//or directly print
	/*for (int i = 0; i < v_colour.size(); i++)
	{
		cout << v_colour[i] << "\n";
	}*/

	
	cout << endl << endl;
	system("pause");
	return 0;
}