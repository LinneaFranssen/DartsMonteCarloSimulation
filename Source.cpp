#include <iostream>
#include <cstdlib>    // random numbers header file
#include <ctime>	  // used to get date and time information
#include <string>

#include "Board.h"
#include "Player.h"
#include "Score.h"
#include "ThrowDecision.h"

using namespace std;

//Create objects
Player player[2] = { Player("Sid",501,99,88,90,80), Player("Joe",501,99,88,90,80) };               //player objects 0 (sid), 1 (joe)
Score score[2] = { Score(), Score() };															   //array of score objects for player 0 and 1
Board board;																					   //board object
ThrowDecision decide;																			   //ThrowDecision object


//Initialise variables
const int totalMatches = 10000;	   //total matches simulated
const int totalSets = 13;		   //total sets played in each match 
const int totalThrowsPerTurn = 3;  //throws per turn

bool playerZeroTurn = 1;         //Sid is player zero and starts
int currentPlayer = -1;          //this later holds whether Sid (0) is the current player or Joe (1)
int initScore = 501;             //initial score in each game, prescribed by the game played

int trackPlayer0Scores[totalMatches] = { 0 }; //Init array that has actual score for number of matches played of player 0 in it
int player0FinalScore[totalSets +1 ] = { 0 };   //Initialise array where I will fill in how often player 0 (sid) gets score 0,...,13; i.e. count how often outcomes occur


//prototype functions
void playSet(int);
void playMatch(int);
void playGame();


int main()              //main loop
{
	srand(time(0)); 	//initialise random num generator using time

	for (int matchNo = 0; matchNo < totalMatches; matchNo++)  //loop through total number of matches to play
	{   
		playerZeroTurn = 1;									  //Sid is player zero and starts each match
		playMatch(matchNo);
		trackPlayer0Scores[matchNo] = score[0].getSetsWon();
	}
	
	int player0FinalScore[totalSets+1] = {                              // array holds number of times player 0 scored score [0,...,13]
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 0) ,  //this means count from array that contains a number of "totalMatches" player 0 scores all that are equal to 0
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 1) ,
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 2) ,
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 3) ,
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 4) ,
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 5) ,
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 6) ,
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 7) ,
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 8) ,
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 9) ,
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 10) ,
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 11) ,
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 12) ,
		count(trackPlayer0Scores, trackPlayer0Scores + totalMatches, 13) 
	};
	
	//screen output for result table
	cout << player[0].getName() << " :   " << player[1].getName() << "    Frequency" << endl;

	for (int i = 0; i < totalSets + 1; i++)
	{
		cout << i                 << "   :   " << totalSets -i              << "      " << player0FinalScore[i]*100/ totalMatches << " %\n";
	}

	int maxPerc = -1;
	int mostCommonScorePlayer0 = -1;
	int winningPlayer = -1;

	//finds result occurring with highest percentage and the corresponding most frequently occurring score of player 0
	for (int i = 0; i < totalSets + 1; i++)
	{
		if (maxPerc < player0FinalScore[i])
		{
			maxPerc = player0FinalScore[i];
			mostCommonScorePlayer0 = i;
		}
	}
	
	//find winning player
	if (mostCommonScorePlayer0 >= 7)
	{
		winningPlayer = 0;
	}
	else { winningPlayer = 1; } 

	//outputs most likely outcome to screen
	cout << "The most likely outcome is that " << player[winningPlayer].getName() << " wins with score " << mostCommonScorePlayer0 << " : " << totalSets - mostCommonScorePlayer0 << " (" << player[0].getName() << " : " << player[1].getName() << ")." <<  endl;
	cout << "These statistics have been computed over " << totalMatches << " matches." << endl;
	cout << "("<< player[0].getName() << " has won " << score[0].getMatchesWon() << " matches and "  << player[1].getName() << " has won " << score[1].getMatchesWon() << " matches.) " << endl;

	while (1) {}     //keeps results displayed
	return 0;
};
	

//fn simulates 1 match
void playMatch(int matchNo)
{
	//reset sets won to 0 
	score[1].setSetsWon(0);
	score[0].setSetsWon(0);
	
	for (int setNo = 0; setNo < totalSets; setNo++)
	{
		
		playSet(setNo);

		playerZeroTurn = !playerZeroTurn;  //flip bool value and hence who throws first in next set  
	
	}

	if (score[1].getSetsWon() < score[0].getSetsWon())
	{
		int won = score[0].getMatchesWon();
		score[0].setMatchesWon(won+1);
	}
	else if (score[0].getSetsWon() < score[1].getSetsWon())
	{
		int won = score[1].getMatchesWon();
		score[1].setMatchesWon(won+1);
	}
	else { cout << "error in playMatch" << endl; }

}

//fn to simulate 1 set
void playSet(int setNo)
{
	//reset games won to 0 
	score[1].setGamesWon(0);
	score[0].setGamesWon(0);

	while ((score[1].getGamesWon() < 3) && (score[0].getGamesWon() < 3))
	{
		playGame();

		if (score[1].getGamesWon() == 3)  //if player 1 has reached 3 game wins first, increase their number of sets won by 1
		{ 
			int setsWon1 = score[1].getSetsWon();
			score[1].setSetsWon(setsWon1+1);
		} 
		else if (score[0].getGamesWon() == 3)  //if player 0 has reached 3 game wins first, increase their number of sets won by 1
		{ 
			int setsWon0 = score[0].getSetsWon();
			score[0].setSetsWon(setsWon0+1);
		} 
		else if (score[0].getGamesWon() > 3 || score[1].getGamesWon() > 3)  { cout << "error in playSet" << endl; }

	}

	
}

//fn to simulate a game
void playGame()
{
    bool playerZeroThrows = playerZeroTurn;   //initially, who's turn it is is dictated from the simulation number of the sets (since who starts alternates between sets) //MISLEADING: CALL PLAYERZEORTHROWS
	score[1].setCurrentGameScore(initScore); //initialise player scores to what the game requires
	score[0].setCurrentGameScore(initScore);


	while ((score[1].getCurrentGameScore() != 0) && (score[0].getCurrentGameScore() != 0)) //repeat procedure of throwing dart until one player has 0 points
	{
		int scoreBeforeThreeThrows = -1;												   //initiate score before turn, used later to store score before throws to make sure it can be reset
		
		//decide who's turn it is
		if (playerZeroThrows == 1) { currentPlayer = 0; }  //Sid is Player 0; Joe Player 1
		else { currentPlayer = 1; }

		//get current player's current score
		Player currentTurnPlayer = player[currentPlayer];
		int scoreAchieved = -1;
		scoreBeforeThreeThrows = score[currentPlayer].getCurrentGameScore(); //store score before throws to make sure it can be reset

		//simulates three throws; exits earlier if won or invalid throw
		for (int throws = 0; throws < totalThrowsPerTurn; throws++)
		{
			int scoreCurrPlayer = score[currentPlayer].getCurrentGameScore();  //score of current player
			bool validFinishThrow = 0;  //(re)set bool-check whether player can finish on score to 0 (i.e. no)

			scoreAchieved = decide.actualTargetHit(scoreCurrPlayer, board, currentTurnPlayer, decide, validFinishThrow);  //returns score hit 

			if (scoreCurrPlayer - scoreAchieved >= 2)   //If score outcome large than 2 or equal to 2, update by subtraction
			{
				score[currentPlayer].setCurrentGameScore(scoreCurrPlayer - scoreAchieved);
				if(throws==totalThrowsPerTurn-1) //change over player only if third throw done
				{
					playerZeroThrows = !playerZeroThrows;
				}
			}
			else if ((scoreCurrPlayer - scoreAchieved == 1 || scoreCurrPlayer - scoreAchieved < 0) || (scoreCurrPlayer - scoreAchieved == 0 && validFinishThrow == 0))  //if invalid, reset to previus and...
			{
				score[currentPlayer].setCurrentGameScore(scoreBeforeThreeThrows);
				playerZeroThrows = !playerZeroThrows; //...change over player
				break;
			}
			else if (scoreCurrPlayer - scoreAchieved == 0 && validFinishThrow == 1)
			{
				score[currentPlayer].setCurrentGameScore(0); //set current player's score to zero
				//update winnings by increasing games won by 1
				int won = score[currentPlayer].getGamesWon();
				score[currentPlayer].setGamesWon(won + 1);
				playerZeroThrows = !playerZeroThrows; //change over player for next game
				break;
			}
			else
			{
				cout << "error scoring" << endl;
			}
			
			
		}

	}

}

