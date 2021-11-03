#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<string>
#include "dictionary.h"

using namespace std;

bool ClassOfDictionary::isSecretWordLegal(string secretWord) {
	int i, j;
	if (secretWord.length() == 5) {
		char tempStr[6];
		secretWord.copy(tempStr, 6);
		tempStr[5] = '\0';

		for (i = 0; i < secretWord.length(); i++) {
			for (j = i + 1; j < secretWord.length(); j++) {
				if (tempStr[i] == tempStr[j])
					return false;
			}
		}
	}
	return true;
}


ClassOfDictionary::ClassOfDictionary() {}

ClassOfDictionary::ClassOfDictionary(char *nameOfInputFile) {
	string tempWord;
	int positionOfElement = 0;
	inputFileForWords.open(nameOfInputFile, ios::in);
	if (!inputFileForWords)
	{
		cout << "There was a problem reading the file or the path was not found!" << endl << endl << endl;
		exit(0);
	}
	else {
		cout << "The file was successfully opened and the dictionary is being created!" << endl;

		while (!inputFileForWords.eof())
		{
			inputFileForWords >> tempWord;
			if (tempWord.length() == 5)
				wordsOfTxt.insert(tempWord);
		}

		for (set<string>::iterator it = wordsOfTxt.begin(); it != wordsOfTxt.end(); ++it)
		{
			tempWord = *it;
			if (isSecretWordLegal(tempWord) == true)
				secretWordsForGame.push_back(tempWord);
		}

	}
}
ClassOfDictionary::~ClassOfDictionary() {}

string ClassOfDictionary::getARandomWordNotRepeatedLetter() {
	srand(time(NULL));
	int lower = 0;
	string secretWordCreated;

	secretWordCreated = secretWordsForGame[rand() % secretWordsForGame.size()];

	return secretWordCreated;
}

bool ClassOfDictionary::isWordInDictionary(string userInputWord) {
	string tempWord;
	for (set<string>::iterator it = wordsOfTxt.begin(); it != wordsOfTxt.end(); ++it)
	{
		tempWord = *it;
		if (userInputWord == tempWord)
			return true;
	}
	return false;
}

