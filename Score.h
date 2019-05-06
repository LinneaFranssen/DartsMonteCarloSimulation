#pragma once

class Score  //stores score info for 1 player
{
private: 
	int gamesWon;
	int setsWon;
	int matchesWon;
	int currentGameScore; //current score

public:

	//constr and destr.
	Score();
	~Score();

	//getters
	int getGamesWon();
	int getSetsWon();
	int getMatchesWon();
	int getCurrentGameScore();

	//setters
	void setGamesWon(int);
	void setSetsWon(int);
	void setMatchesWon(int);
	void setCurrentGameScore(int);
};

