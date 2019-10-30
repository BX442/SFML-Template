#include "pch.h"
#include <iostream>
#include "Settings.h"
#include "Render.h"
#include "Actor.h"
#include "Cell.h"
#include "Game.h"

// TODO:Создать класс Text.
// TODO:Пересоздавать атлас спрайтов только с актуальными спрайтами.

extern Sprite g_packMan;
extern Actor packMan;
extern Cell *g_map[22][22];

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

extern Game mainGame;
void Render::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	unsigned short hPos = 0;
	unsigned int object = 0;
	//sf::Sprite sprite;
	//sprite.setTexture(g_mainTexture);
	//sprite.setTextureRect(sf::IntRect(19 * g_spriteSize, 16 * g_spriteSize, g_spriteSize, g_spriteSize));
	for (auto h = 0; h < 22; h++)
	{
		hPos = h * 32;
		
		for (auto w = 0; w < 22; w++)
		{
			//sprite.setTextureRect(sf::IntRect(w * g_spriteSize, h * g_spriteSize, g_spriteSize, g_spriteSize));
			//mainGame.getMapCell(0,0).getCellSprite()->getSprite();
			mainGame.getMapCell(h,w).getCellSprite()->sprite.setPosition(w * 32, hPos);
			target.draw(mainGame.getMapCell(h, w).getCellSprite()->sprite, states);
		}
	}
	for (size_t act = 0; act < 4; act++)
	{

		target.draw(mainGame.getActor(act).getActorSprite()->sprite, states);
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

/*
 	for (auto& h : dmoveMap)
	{
		for (unsigned short& w : h)
		{
			w = 0;
		}
	}

	//Было:
	//for (__int8 h = 0; h < 22; h++)
	//{
	//	for (__int8 w = 0; w < 22; w++)
	//	{
	//		dmoveMap[h][w] = 0;
	//	}
	//}
*/