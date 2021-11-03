#ifndef GAME_H
#define GAME_H

#include "dictionary.h"

class ClassOfGamesWords : public ClassOfDictionary {
private:
	string secretWordOfGame = "";
	int numberOfPredictions = 0;
	bool isCheatUsed = false;

	int howManyLettersMatched(string);
	int howManyTruePlace(string);

public:
	ClassOfGamesWords();
	~ClassOfGamesWords();

	void startToPlayGame(ClassOfGamesWords &);

};

#endif // !GAME_H
