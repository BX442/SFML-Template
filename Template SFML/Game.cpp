#include "pch.h"
#include "Game.h"

extern Sprite g_packMan;
extern Sprite g_ghostMan;

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
			dmoveMap[h][w] = 0;
		}
	}

	dactors[0] = Actor(1, false, g_packMan);
	dactors[1] = Actor(2, true, g_ghostMan);
	dactors[2] = Actor(3, true, g_ghostMan);
	dactors[3] = Actor(4, true, g_ghostMan);

	dmoveMap[21][11] = 1;
	dmoveMap[10][9] = 2;
	dmoveMap[10][10] = 3;
	dmoveMap[10][11] = 4;
}

//Game& Game::operator=(const Game&& ref)
//{
//	// TODO: вставьте здесь оператор return
//}



void *Game::getMap()
{
	return dmap;
}

Cell &Game::getMapCell(unsigned int x, unsigned int y)
{
	return *dmap[x][y];
}


