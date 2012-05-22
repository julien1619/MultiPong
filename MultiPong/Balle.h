#pragma once
class Balle
{
public:
	Balle(void);
	Balle(int masse, int rayon);
	virtual ~Balle(void);

	void update(int x, int y, int speed, int dirX, int dirY);
	int getX();
	int getY();
	int getSpeed();
	int getDirX();
	int getDirY();
	int getMasse();
	int getRayon();

private:
	int posX;
	int posY;
	int speed;
	int masse;
	int dirX;
	int dirY;
	int rayon;
};

