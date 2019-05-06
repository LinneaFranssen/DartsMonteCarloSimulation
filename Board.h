#pragma once

class Board
{
private:
	//dartboard matrix
	static const int dartBoard[2][21];

public:
	Board();
	~Board();

//throw fns
int throwSingle(int, int, int, bool&);
int throwDouble(int, int, bool&);
int throwTreble(int, int);
int throwBull(int, bool&);
}; 
