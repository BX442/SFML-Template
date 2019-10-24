#include "pch.h"
#include <iostream>
#include "Settings.h"
#include "Render.h"
#include "Actor.h"

// TODO:Создать класс Text.
// TODO:Пересоздавать атлас спрайтов только с актуальными спрайтами.

Render::Render()
{
	this->dfont.loadFromFile("data/fonts/Arial.ttf");
	this->dfps.setCharacterSize(12);
	this->dfps.setFont(this->dfont);
	this->dfps.setPosition(600.f - 60.f, 10.f);
	this->dfps.setString("0.0");
	
	this->dfieldHeight = g_settings.GetHeight() / g_settings.GetSpriteSize();
	this->dfieldWidth = g_settings.GetWidth() / g_settings.GetSpriteSize();
	this->dtileCount = dfieldHeight * dfieldWidth;

	std::cout << "Размер экрана в плитках: " << this->GetFieldWidth() << 'x' << this->GetFieldHeight() << std::endl;
}

int Render::GetFieldHeight() const
{
	return dfieldHeight;
}

int Render::GetFieldWidth() const
{
	return dfieldWidth;
}

void Render::SetFpsCount(std::string fps)
{
	this->dfps.setString(fps);
}
extern Sprite g_packMan;
extern Actor packMan;
void Render::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	sf::Sprite sprite;
	sprite.setTexture(g_mainTexture);
	sprite.setTextureRect(sf::IntRect(19 * g_spriteSize, 16 * g_spriteSize, g_spriteSize, g_spriteSize));
	for (auto h = 0; h < dfieldHeight; h++)
	{
		const unsigned short hPos = h * 32;
		
		for (auto w = 0; w < dfieldWidth-1; w++)
		{
			//sprite.setTextureRect(sf::IntRect(w * g_spriteSize, h * g_spriteSize, g_spriteSize, g_spriteSize));
			//sprite.setPosition(w * 32, hPos);
			target.draw(packMan.getActorSprite()->getSprite(), states);
		}
	}
	
	/*
	//for (auto i = 0; i < dtileCount; i++)
	for (auto i = 0; i < 41; i++)
	{

		sf::Vector2f position(static_cast<float> ((i % dfieldWidth) * sprite_size), static_cast<float>((i / dfieldHeight) * sprite_size));
		//test_tile.SetTestSprite(11, 9, static_cast<float > ((i+1 % dfieldHeight)) * SPRITE_SIZE, static_cast<float>((i+1 / dfieldWidth)) * SPRITE_SIZE);
		//std::cout << "Позиция спрайта №" << i << " по X: " << position.x * SPRITE_SIZE << std::endl;
		std::string count = std::to_string(i);
		sf::Text text(count, dfont, 10);
		text.setPosition(position);
		target.draw(test_tile.GetSprite(), states);
		//target.draw(text, states);
	}
	*/
}