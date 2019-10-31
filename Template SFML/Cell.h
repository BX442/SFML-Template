#pragma once
#include "Sprite.h"

/*
 * Материал объекта -> Спрайт
 * Тип объекта
 */
class Cell
{
protected:
	int dmapPart; // 0 - Пустота, 1 - Стена, 2 - Пол
	Sprite &dCellSprite;
	//Material
public:
	Cell();
	Cell(Sprite &Ref, int object = 1);
	Cell &operator=(const Cell &ref);

	Sprite *getCellSprite();

	// * Возможно ли пройти по плитке "0 - Пустота, 1 - Стена, 2 - Пол"
	int getPassability();
};
