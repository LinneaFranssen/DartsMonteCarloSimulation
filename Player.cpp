#include "Player.h"
#include <string>
using namespace std;


//constructor

Player::Player(string n, int pB, int pO, int pS, int pD, int pT)
{
	name = n;

	pBull = pB;

	pOuter = pO;

	pSingle = pS;

	pDouble = pD;

	pTreble = pT;
}


//destructor

Player::~Player()
{
}

// getter fns

string Player::getName() {

	return name;

};

int Player::getPBull() {

	return pBull;

};

int Player::getPOuter() {

	return pOuter;

};


int Player::getPSingle() {

	return pSingle;

};

int Player::getPDouble() {

	return pDouble;

};

int Player::getPTreble() {

	return pTreble;

};



//setters

void Player::setName(string n) {

	name = n;

};


void Player::setPBull(int pB) {

	pBull = pB;

};

void Player::setPOuter(int pO) {

	pBull = pO;

};

void Player::setPSingle(int pS) {

	pSingle = pS;

};

void Player::setPDouble(int pD) {

	pDouble = pD;

};

void Player::setPTreble(int pT) {

	pTreble = pT;

};





