#include "pch.h"
#include "Game.h"

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
			}
		}
	}
}



void *Game::getMap()
{
	return dmap;
}

Cell &Game::getMapCell(unsigned int x, unsigned int y)
{
	return *dmap[x][y];
}


