#pragma once
#include "Sprite.h"

/*
 * �������� ������� -> ������
 * ��� �������
 */
class Cell
{
protected:
	Sprite &dCellSprite;
	//Material
	unsigned __int8 dmapPart = 1; // 0 - �������, 1 - �����, 2 - ���
public:
	Cell();
	Cell(Sprite &Ref, unsigned __int8 = 1);
	Cell &operator=(const Cell &ref);

	Sprite *getCellSprite();
};
