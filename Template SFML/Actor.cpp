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


void Actor::moveActor(Direction dir, Cell *cell[])
{
	//TODO: ПОнять почему cell возвращает 1 вместо 2 и наоборот...

	std::cout << cell[0]->getPassability() << std::endl;
	switch (dir)
		{
		case FORWARD:
			if (dy - 1 > -1)
			{
				std::cout << dy - 1 << std::endl;
				std::cout << cell[(dy - 1) * dx]->getPassability() << std::endl;
				if (cell[(dy - 1)*dx]->getPassability() == 1)
				{
					std::cout << cell[(dy - 1) * dx]->getPassability() << std::endl;
					dy--;
				}
			}
			break;
		case BACKWARD:
			if (dy+1 < 23)
			{
				if (cell[dy + 1][dx].getPassability() == 2)
				{
					dy++;
				}
			}
			break;
		case LEFT:
			if (dx - 1 > -1)
			{
				if (cell[dy][dx - 1].getPassability() == 2)
				{
					dx--;
				}
			}
			break;
		case RIGHT:
			if (dx + 1 < 23)
			{
				if (cell[dy][dx + 1].getPassability() == 2)
				{
					dx++;
				}
			}
			break;
		case UP: break;
		case DOWN: break;
		default:
			std::cout << "Ошибка направления движения" << std::endl; break;
		}
		dActorSprite.sprite.setPosition(dx * g_spriteSize, dy * g_spriteSize);
}

int Actor::getX()
{
	return dx;
}

int Actor::getY()
{
	return dy;
}

int Actor::getZ()
{
	return dz;
}

