#include "pch.h"
#include "Cell.h"

Cell::Cell() :dCellSprite(*new Sprite)
{
}

Cell::Cell(Sprite &Ref, unsigned __int8 object) : dCellSprite(Ref)
{
	dCellSprite = Ref;
	dmapPart = object;
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