#pragma once
class Raquette
{
public:
	Raquette();
	Raquette(int length, int height);
	virtual ~Raquette(void);

	void update(int pos, int speed);
	int getX();
	int getLength();
	int getHeight();
	int getSpeed();

private:
	int x;
	int length;
	int height;
	int speed;
};

