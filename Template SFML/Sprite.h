#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"

class Sprite
{
protected:
	sf::Sprite dsprite;
	//dsprite.setTexture(g_mainTexture);
	//dsprite.setTextureRect(sf::IntRect(11 * g_spriteSize, 9 * g_spriteSize, g_spriteSize, g_spriteSize));
	//dsprite.setPosition(0, 0);
public:
	Sprite();
	//~Sprite();
	Sprite(int rectLeft, int rectTop, unsigned short spriteSize);
	void setPosition(short, short);

	sf::Sprite getSprite();
};


class SpriteSet
{
protected:
	unsigned int did;
	
};
