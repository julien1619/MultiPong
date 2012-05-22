#pragma once
#include "Raquette.h"

enum playerType {LOCAL,NET};
enum playerState {PLAYING,WAITING,DEAD};

class player
{
public:
	player(void);
	virtual ~player(void);

private:
	int id;
	playerType type;
	int score;
	Raquette raquette;
	//Bonus bonus;
};

