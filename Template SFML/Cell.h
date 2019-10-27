#pragma once
#include "Sprite.h"

/*
 * Материал объекта -> Спрайт
 * Тип объекта
 */
class Cell
{
protected:
	Sprite &dCellSprite;
	//Material
	unsigned __int8 dmapPart = 1; // 0 - Пустота, 1 - Стена, 2 - Пол
public:
	Cell();
	Cell(Sprite &Ref, unsigned __int8 = 1);
	Cell &operator=(const Cell &ref);

	Sprite *getCellSprite();
};
