#pragma once
#include "Sprite.h"

class Actor
{
protected:
	unsigned int did;
	bool denemy = true;
	Sprite &dActorSprite;
public:
	Actor() :dActorSprite(*new Sprite) {};
	Actor(unsigned int, bool, Sprite &Ref);
	Actor &operator=(const Actor&&ref);

	Sprite *getActorSprite();
	auto getId();
	auto getEnemyStatus();

	void moveActor() {};
};