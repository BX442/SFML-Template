#include "pch.h"
#include "Graphics.h"
#include <iostream>

Graphics::Graphics()
{
	if (!this->dtileSet.loadFromFile("data/images/tileset/set_max.png"))
	{
		std::cout << "Не удалось загрузить: " << "data/images/tileset/set_max.png" << std::endl;
	}
	dmainTexture.loadFromImage(dtileSet);
	this->dtileSet.~Image();
}

Graphics::Graphics(const std::string& filename)
{
	if (!dtileSet.loadFromFile(filename))
	{
		std::cout << "Не удалось загрузить: " << filename << std::endl;
	}else
	{
		dmainTexture.loadFromImage(dtileSet);
		dtileSet.~Image();
	}
}

void Graphics::SetTexture()
{
	dmainTexture.loadFromImage(dtileSet);
}

sf::Texture Graphics::GetTexture() const
{
	return dmainTexture;
}
