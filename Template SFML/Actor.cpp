#include "pch.h"
#include "Actor.h"


Actor::Actor(unsigned int id, bool enemy, Sprite &Ref) : dActorSprite(Ref)
{
	did = id;
	denemy = enemy;
	dActorSprite = Ref;
}

Actor &Actor::operator=(const Actor&&ref)
{
	did = ref.did;
	denemy = ref.denemy;
	dActorSprite = ref.dActorSprite;
	return *this;
}

Sprite *Actor::getActorSprite()
{
	return &dActorSprite;
}

unsigned int Actor::getId()
{
	return did;
}

bool Actor::getEnemyStatus()
{
	return denemy;
}
