#include "pch.h"
#include "Actor.h"
#include <iostream>


Actor::Actor() : dx(0), dy(0), dz(0), did(0), dActorSprite(*new Sprite)
{
}

Actor::Actor(unsigned int id, bool enemy, Sprite &Ref, int posX, int posY, int posZ) : dx(posX), dy(posY), dz(posZ), did(id), denemy(enemy), dActorSprite(Ref)
{
	dx = posX;
	dy = posY;
	dz = posZ;
	did = id;
	denemy = enemy;
	dActorSprite.sprite.setPosition(posX * g_spriteSize, posY * g_spriteSize);
	//std::cout << "Spite coord in Actor: x" << posX << " y" << posY << std::endl;

}

Actor &Actor::operator=(const Actor&&ref)
{
	dx = ref.dx;
	dy = ref.dy;
	dz = ref.dz;
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

void Actor::moveActor(Direction dir)
{
	std::cout << "Координата спрайта: x" << dx << " y" << dy << std::endl;
	switch (dir)
	{
	case FORWARD:
		dy--;
		break;
	case BACKWARD:
		dy++;
		break;
	case LEFT:
		dx--;
		break;
	case RIGHT:
		dx++;
		break;
	case UP: break;
	case DOWN: break;
	default:
		std::cout << "Ошибка направления движения" << std::endl; break;
	}

	dActorSprite.sprite.setPosition(dx * g_spriteSize, dy * g_spriteSize);
	std::cout << "Координата спрайта: x" << dx << " y" << dy << std::endl;

}

