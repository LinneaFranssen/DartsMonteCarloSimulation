#include "Board.h"
using namespace std;
#include <cstdlib>    // random numbers header file  
#include <ctime>	  // used to get date and time information

Board::Board()
{
}


Board::~Board()
{
}


//the dartboard is set up such that for element 1=dart field 1, the neighbours (20,18) are in the array etc.
const int Board::dartBoard[2][21] = 
{ 
	{ 0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5 }, //numbers on dartboard anticlockwise
	{ 0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1 }  //numbers on dartboard clockwise
};

//all functions to come return the score hit by the throw

int Board::throwBull(int p, bool &iV) {

    //  Throw for the bull with accuracy p%; iV stands for "is this valid as a finishing throw?"

	int r = rand() % 100;  //should be 1000

	if (r < p)  // formerly: hit bull with p=accurancy-20% // I changed this because it made no sense to me that, if the accuracy is p%, the probability of hitting accurately should be p%-20%
	{
		iV = 1; ; //iV stands for "is this valid as a finishing throw?" (yes, it is)
		return 50;
	}
	else if (r < p + (100 - p)*0.6)  // hit 25 with accuracy a 60% given that not to hit as intended
	{
		return 25;
	}
	else //remaining 40% (given that not to hit as intended) return any other single number with the same probability
	{
		return 1 + rand() % 20;
	} 
}


int Board::throwTreble(int d, int p) {

	// return result of throwing for treble d with accuracy p% ; iV stands for "is this valid as a finishing throw?". This is unchanged and hence would not have been needed

	int r = rand() % 100;

	if (r < p)
	{
		return 3 * d;
	}
	else if (r < p + (100 - p)*0.2)  //return single value (and other 'miss' options) with a fifth of the probability not to hit as intended etc.
	{
		return d;
	}
	else if (r < p + 2 * (100 - p)*0.2)
	{
		return 3 * dartBoard[0][d];
	}
	else if (r < p + 3 * (100 - p)*0.2)
	{
		return 3 * dartBoard[1][d];
	}
	else if (r < p + 4 * (100 - p)*0.2)
	{
		return dartBoard[0][d];
	}
	else
	{
		return dartBoard[1][d];
	}
}


int Board::throwDouble(int d, int p, bool &iV) {

	//  return result of throwing for double d with accuracy p%

	int r = rand() % 100;

	if (r < p)
	{
		iV = 1;
		return 2 * d;
	}
	else if (r < p + 1 * (100 - p)*0.3) //return single value and zero (complete 'miss' options) with 30% of the probability not to hit as intended 
	{
		return 0;
	}
	else if (r < p + 2 * (100 - p)*0.3)
	{
		return d;
	}
	else if (r < p + 2 * (100 - p)*0.3 + 2 * (100 - p)*0.15)  //return each neighbouring double with 15% of the probability not to hit as intended 
	{
		iV = 1;
		return 2 * dartBoard[0][d];
	}
	else if (r < p + 2 * (100 - p)*0.3 + 3 * (100 - p)*0.15)
	{
		iV = 1;
		return 2 * dartBoard[1][d];
	}
	else if (r < p + 2 * (100 - p)*0.3 + 4 * (100 - p)*0.05) //return each neighbouring single with 5% of the probability not to hit as intended 
	{
		return dartBoard[0][d];
	}
	else
	{
		return dartBoard[1][d];
	}
}



int Board::throwSingle(int d, int p, int q, bool &iV) 
{

	//  return result of throwing for single d with accuracy p% (or q% for the outer)

	int r = rand() % 100;

	if (d == 25) {		// outer with q% accuracy

		if (r < q)
		{
			return 25;
		}

		else if (r < q + (100 - q)*0.5)
		{
			iV = 1;
			return 50;
		}
			
		else
		{
			return 1 + rand() % 20;
		}
	}

	else			// 1 to 20 single with accuracy p%
	{
		if (r < p)
		{
			return d;
		}
		else if (r < p + 1 * (100 - p)*0.3)
		{
			return dartBoard[0][d];
		}
		else if (r < p + 2 * (100 - p)*0.3)
		{
			return dartBoard[1][d];
		}
		else if (r < p + 2 * (100 - p)*0.3 + (100 - p)*0.2)
		{
			return 3 * d;
		}
		else
		{
			iV = 1;
			return 2 * d;
		}
	}
}
