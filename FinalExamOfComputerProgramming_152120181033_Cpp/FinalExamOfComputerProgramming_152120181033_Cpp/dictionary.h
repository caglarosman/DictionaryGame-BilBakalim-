#ifndef DICTIONARY_H
#define DICTIONARY_H

#include<vector>
#include<set>
#include<fstream>

using namespace std;

class ClassOfDictionary {
private:
	fstream inputFileForWords;
	set<string> wordsOfTxt;
	vector<string> secretWordsForGame;

	bool isSecretWordLegal(string secretWord);
		
public:
	ClassOfDictionary();
	ClassOfDictionary(char *);
	~ClassOfDictionary();

	string getARandomWordNotRepeatedLetter();
	bool isWordInDictionary(string);
};



#endif // !DICTIONARY_H
