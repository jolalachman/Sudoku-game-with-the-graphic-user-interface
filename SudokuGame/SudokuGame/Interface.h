#pragma once
#include "Gameplay.h"
class Interface
{
private:
	std::string entry_username;
	long int currentScore;
	long int highestScore;
	Gameplay game;
public:
	void login();
	void newSudoku();
	void addNumber();
	bool isComplete();
	void reloadSudoku();
	void endSudoku();
	void winSudoku();
	void cheat();
};

