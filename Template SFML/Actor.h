#pragma once
#include "Sprite.h"

enum Direction
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Actor
{
protected:
	int dx;
	int dy;
	int dz;
	unsigned int did;
	bool denemy = true;
	Sprite &dActorSprite;
public:
	Actor();
	Actor(unsigned int id, bool enemy, Sprite& Ref, int posX, int posY, int posZ=1);
	Actor &operator=(const Actor&&ref);

	Sprite *getActorSprite();
	unsigned int getId();
	bool getEnemyStatus();

	void moveActor(Direction dir);

	int getX() { return dx; };
	int getY() { return dy; };
	int getZ() { return dz; };
};