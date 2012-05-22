#include "Raquette.h"


Raquette::Raquette()
{
	this->x = 0;
	this->length = 20;
	this->height = 3;
	this->speed = 0;
}

Raquette::Raquette(int length, int height)
{
	this->x = 0;
	this->length = length;
	this->height = height;
	this->speed = 0;
}


Raquette::~Raquette()
{
}

void Raquette::update(int pos, int speed)
{
	this->x = pos;
	this->speed = speed;
}

int Raquette::getX()
{
	return this->x;
}

int Raquette::getLength()
{
	return this->length;
}

int Raquette::getHeight()
{
	return this->height;
}

int Raquette::getSpeed()
{
	return this->speed;
}
