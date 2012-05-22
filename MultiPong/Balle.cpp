#include "Balle.h"


Balle::Balle(void)
{
	this->masse = 3;
	this->rayon = 3;
	this->dirX = 0;
	this->dirY = 0;
	this->posX = 0;
	this->posY = 0;
	this->speed = 0;
}

Balle::Balle(int masse, int rayon)
{
	this->masse = masse;
	this->rayon = rayon;
	this->dirX = 0;
	this->dirY = 0;
	this->posX = 0;
	this->posY = 0;
	this->speed = 0;
}


Balle::~Balle(void)
{
}

void Balle::update(int x, int y, int speed, int dirX, int dirY)
{
	this->posX = x;
	this->posY = y;
	this->speed = speed;
	this->dirX = dirX;
	this->dirY = dirY;
}

int Balle::getX()
{
	return this->posX;
}

int Balle::getY()
{
	return this->posY;
}

int Balle::getSpeed()
{
	return this->speed;
}

int Balle::getDirX()
{
	return this->dirX;
}

int Balle::getDirY()
{
	return this->dirY;
}

int Balle::getMasse()
{
	return this->masse;
}

int Balle::getRayon()
{
	return this->rayon;
}
