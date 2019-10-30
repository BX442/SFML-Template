#include "pch.h"
#include "Sprite.h"
#include <iostream>

Sprite::Sprite()
{
	sprite.setTexture(g_mainTexture);
	sprite.setTextureRect(sf::IntRect(6 * g_spriteSize, 1 * g_spriteSize, g_spriteSize, g_spriteSize));
}

Sprite::Sprite(int rectLeft, int rectTop, unsigned short spriteSize)
{
	sprite.setTexture(g_mainTexture);
	sprite.setTextureRect(sf::IntRect(rectLeft * spriteSize, rectTop * spriteSize, spriteSize, spriteSize));
}