#pragma once
#include "Sprite.h"

class Actor
{
protected:
	Sprite &dActorSprite;
public:
	Actor() :dActorSprite(*new Sprite) {};
	Actor(Sprite &Ref);
	Actor &operator=(const Actor &&ref);

	Sprite *getActorSprite();
};