#include "pch.h"
#include "Actor.h"


Actor::Actor(Sprite &Ref) : dActorSprite(Ref)
{
	dActorSprite = Ref;
}

Actor &Actor::operator=(const Actor &&ref)
{
	dActorSprite = ref.dActorSprite;
	return *this;
}

Sprite *Actor::getActorSprite()
{
	return &dActorSprite;
}
