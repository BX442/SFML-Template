#include "pch.h"
#include "Settings.h"

__int16 Settings::GetWidth() const
{
	return dwidth;
}

__int16 Settings::GetHeight() const
{
	return dheight;
}

unsigned __int8 Settings::GetSpriteSize() const
{
	return dspriteSize;
}

Settings::Settings()
{
	dwidth = 1280;
	dheight = 720;
	dspriteSize = 32;
}
//Settings g_settings;