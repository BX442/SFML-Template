#pragma once
#include "Graphics.h"
#include "Random.h"

extern Graphics g_gameGraphics;
extern sf::Texture g_mainTexture;
extern unsigned __int8 g_spriteSize;

class Settings
{
protected:
	__int16 dwidth = 640;
	__int16 dheight = 480;
	unsigned __int8 dspriteSize = 32;

public:
	Settings();
	__int16 GetWidth() const;
	__int16 GetHeight() const;
	unsigned __int8 GetSpriteSize() const;
};