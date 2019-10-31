#pragma once
#include "Sprite.h"

/*
 * �������� ������� -> ������
 * ��� �������
 */
class Cell
{
protected:
	int dmapPart; // 0 - �������, 1 - �����, 2 - ���
	Sprite &dCellSprite;
	//Material
public:
	Cell();
	Cell(Sprite &Ref, int object = 1);
	Cell &operator=(const Cell &ref);

	Sprite *getCellSprite();

	// * �������� �� ������ �� ������ "0 - �������, 1 - �����, 2 - ���"
	int getPassability();
};
