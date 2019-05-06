#pragma once

#include "Board.h"
#include "Player.h"

class ThrowDecision
{
public:
	//constructor and destructor
	ThrowDecision();
	~ThrowDecision();

	//fn returns target SCORE to aim for
	int throwDecision(int);

	//fn returns score of target actually hit
	int actualTargetHit(int, Board, Player, ThrowDecision, bool&);  
};


