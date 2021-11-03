//this program reads records from a text file and assign set<string>
#include <iostream>
#include <fstream>
#include<string>
#include<set>
using namespace std;

int main()
{

	fstream dataFile;
	set<string> words;
	string tmp;

	
	char filename[30];

	cout << "Enter file name to open:" << endl;
	cin >> filename;



	dataFile.open(filename, std::fstream::in);
	if (!dataFile)
	{
		cout << "File open error!" << endl;
		exit(0);
	}
	else
	{
		cout << "File opened successfully!" << endl;

		dataFile >> tmp;
		while (!dataFile.eof())
		{
			words.insert(tmp);
			dataFile >> tmp;
		}


		for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
		{
			cout << *it << endl;
		}







	cout << endl << endl;
	system("pause");
	return 0;
}




}