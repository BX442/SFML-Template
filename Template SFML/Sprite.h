#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"

class Sprite
{
protected:
	
public:
	sf::Sprite sprite;
	
	Sprite();
	Sprite(int rectLeft, int rectTop, unsigned short spriteSize);
};


