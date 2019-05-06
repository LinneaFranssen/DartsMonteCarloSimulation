#include "Score.h"

//constructor
Score::Score()
{
	gamesWon = 0;
	setsWon = 0;
	matchesWon = 0;
	currentGameScore = 501;
}

//destructor
Score::~Score()
{
}


	// getters

	int Score::getGamesWon() 
	{

		return gamesWon;

	};

	int Score::getSetsWon() 
	{

		return setsWon;

	};

	int Score::getMatchesWon() 
	{
		return matchesWon;
	};

	int Score::getCurrentGameScore() {

		return currentGameScore;

	};


	//setters


	void Score::setGamesWon(int gW) {

		gamesWon = gW;

	};

	void Score::setSetsWon(int sW) {

		setsWon = sW;

	};

	void Score::setMatchesWon(int mW)
	{
		matchesWon = mW;
	};

	void Score::setCurrentGameScore(int s) {

		currentGameScore = s;

	};
