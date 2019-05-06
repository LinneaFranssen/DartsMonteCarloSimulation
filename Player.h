#pragma once
#include <string>
using namespace std;

class Player
{
private:

	string name;

	//throw probabilities
	int pBull;
	int pOuter;
	int pSingle;
	int pDouble;
	int pTreble;


public:

	//constructor

	Player(string, int, int, int, int, int);


	//destructor

	~Player();



	// getter fns

	string getName();

	int getPBull();

	int getPOuter();

	int getPSingle();

	int getPDouble();

	int getPTreble();


	// setter fns

	void setName(string);

	void setPBull(int);

	void setPOuter(int);

	void setPSingle(int);

	void setPDouble(int);

	void setPTreble(int);
};



