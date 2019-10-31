#include "pch.h"
#include "Cell.h"
#include <iostream>

extern Sprite g_floor_sprite;

Cell::Cell() :dmapPart(0), dCellSprite(*new Sprite)
{
}

Cell::Cell(Sprite &Ref, int object): dmapPart(object), dCellSprite(Ref)
{
}

Cell &Cell::operator=(const Cell &ref)
{
	dCellSprite = ref.dCellSprite;
	dmapPart = ref.dmapPart;
	return *this;
}

Sprite *Cell::getCellSprite()
{
	return &dCellSprite;
}

int Cell::getPassability()
{
	return dmapPart;
}
