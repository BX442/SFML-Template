#include "pch.h"
#include "Game.h"
#include <iostream>

extern Sprite g_packMan;
extern Sprite g_ghostMan;
extern Sprite g_floor_sprite;
extern Cell g_wall;
extern Cell g_floor;

Game::Game(unsigned short (&array)[22][22])
{
	for (auto h = 0; h < 22; h++)
	{
		for (auto w = 0; w < 22; w++)
		{
			if (array[h][w] == 0)
			{
				dmap[h][w] = &g_wall;
			}
			else
			{
				dmap[h][w] = &g_floor;
				//std::cout << g_floor.getPassability() << std::endl;
			}
		}
	}
	std::cout << "Проходимость g_wall при инициализации карты в конструкторе: " << g_wall.getPassability() << '\n' <<
				 "Проходимость нуля при инициализации карты в конструкторе g_wall'ом: " << dmap[0][0]->getPassability() << std::endl;
	dactors[0] = Actor(1, false, g_packMan,11,20);
	dactors[1] = Actor(2, true, g_ghostMan,9,10);
	dactors[2] = Actor(3, true, g_ghostMan, 10, 10);
	dactors[3] = Actor(4, true, g_ghostMan, 11, 10);
	//Cell test(g_floor_sprite, 4);
	
	
}

Cell **Game::getMap()
{
	return *dmap;
}


Cell &Game::getMapCell(unsigned int x, unsigned int y)
{
	return *dmap[x][y];
}

Actor &Game::getActor(unsigned int actorId)
{
	return dactors[actorId];
}

Actor *Game::getActors()
{
	return dactors;
}
