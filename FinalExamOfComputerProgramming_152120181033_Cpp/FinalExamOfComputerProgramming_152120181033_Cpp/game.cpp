#include<iostream>
#include<stdlib.h>
#include<string>
#include "game.h"

using namespace std;

int ClassOfGamesWords::howManyLettersMatched(string guessOfUser) {
	int countLetter = 0, i, j, k, flag;
	char tempStr[6], tempGuess[6];
	strcpy_s(tempStr, secretWordOfGame.c_str());
	strcpy_s(tempGuess, guessOfUser.c_str());
	tempGuess[5] = '\0';//tahmin kelimesi
	tempStr[5] = '\0';//secret kelime


	for (i = 0; i < guessOfUser.length(); i++) {
		flag = 1;//uygun fora girebilir
		for (k = i - 1; k >= 0; k--) {
			if (tempGuess[i] == tempGuess[k]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			for (j = 0; j < guessOfUser.length(); j++) {
				if (tempGuess[i] == tempStr[j])
					countLetter++;
			}
		}

	}
	return countLetter;
}

int ClassOfGamesWords::howManyTruePlace(string guessOfUser) {
	int countTruePlace = 0, i;
	char tempStr[6], tempGuess[6];
	strcpy_s(tempStr, secretWordOfGame.c_str());
	strcpy_s(tempGuess, guessOfUser.c_str());
	tempGuess[5] = '\0';
	tempStr[5] = '\0';

	for (i = 0; i < guessOfUser.length(); i++) {
		if (tempGuess[i] == tempStr[i])
			countTruePlace++;
	}
	return countTruePlace;
}


ClassOfGamesWords::ClassOfGamesWords() {}
ClassOfGamesWords::~ClassOfGamesWords() {}

void ClassOfGamesWords::startToPlayGame(ClassOfGamesWords &) {
	char nameOfFileWords[] = "words.txt";
	ClassOfDictionary dictionaryObject(nameOfFileWords);
	secretWordOfGame = dictionaryObject.getARandomWordNotRepeatedLetter();
	//secretWordOfGame = "credo"; //Test kelimesi koyma yeri.
	string userGuessWord;
	int normalFlag = 0;

	cout << "\n\t\t\t\t < Welcome to the BilBakalim Game! >" << endl;
	cout << "Secret word is: " << secretWordOfGame << endl
		<< "---------------------" << endl;

	while (true) {

		cout << "\nEnter prediction word: ";
		cin >> userGuessWord;

		numberOfPredictions++;

		if (dictionaryObject.isWordInDictionary(userGuessWord) == false && userGuessWord != "xxxxx") {
			cout << "Word not found in dictionary!" << endl;
			if (numberOfPredictions == 0)
				numberOfPredictions = 0;
			else
				numberOfPredictions--;
		}
		if (userGuessWord == "xxxxx") {
			isCheatUsed = true;
			cout << "< Hint: Secret word: " << secretWordOfGame << " >" << endl;
		}
		if (userGuessWord == secretWordOfGame)
			break;
		if (isCheatUsed == true && normalFlag == 0) {
			//numberOfPredictions++;
			normalFlag = 1;
		}



		if (dictionaryObject.isWordInDictionary(userGuessWord) == true && userGuessWord != "xxxxx") {
			cout << "Number of matching letters: " << howManyLettersMatched(userGuessWord) << endl;
			cout << "Correct position of matching letters: " << howManyTruePlace(userGuessWord) << endl;

		}


	}
	if (isCheatUsed == true)
		cout << "\n< Congratulations, you finished the contest at the " << numberOfPredictions << ". guess! (Using Hint) >" << endl;
	else
		cout << "\n< Congratulations, you finished the contest at the " << numberOfPredictions << ". guess! (Without Hint) >" << endl;
}
