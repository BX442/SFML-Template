#include "pch.h"
#include "Sprite.h"

Sprite::Sprite()
{
	dsprite.setTexture(g_mainTexture);
	dsprite.setTextureRect(sf::IntRect(6 * g_spriteSize, 1 * g_spriteSize, g_spriteSize, g_spriteSize));
	dsprite.setPosition(0, 0);
}

Sprite::Sprite(int rectLeft, int rectTop, unsigned short spriteSize)
{
	dsprite.setTexture(g_mainTexture);
	dsprite.setTextureRect(sf::IntRect(rectLeft * g_spriteSize, rectTop * g_spriteSize, g_spriteSize, g_spriteSize));
}

void Sprite::setPosition(short X, short Y)
{
	dsprite.setPosition(X, Y);
}

sf::Sprite Sprite::getSprite()
{
	return dsprite;
}
