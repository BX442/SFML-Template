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
	dfont.loadFromFile("data/fonts/Arial.ttf");
	dtext.setCharacterSize(32);
	dtext.setFont(dfont);
	
	
	dfieldHeight = g_settings.GetHeight() / g_settings.GetSpriteSize();
	dfieldWidth = g_settings.GetWidth() / g_settings.GetSpriteSize();
	dtileCount = dfieldHeight * dfieldWidth;

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

void Render::SetText(std::string &text, float x, float y)
{
	dtext.setString(text);
	dtext.setPosition(x, y);
}

void Render::SetText(int text, float x, float y)
{
	dtext.setString(std::to_string(text));
	dtext.setPosition(x, y);
}

extern Game mainGame;

void Render::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	unsigned short hPos = 0;
	unsigned int object = 0;
	sf::Text text("", dfont,32);
	//sf::Sprite sprite;
	//sprite.setTexture(g_mainTexture);
	//sprite.setTextureRect(sf::IntRect(19 * g_spriteSize, 16 * g_spriteSize, g_spriteSize, g_spriteSize));
	for (auto h = 0; h < 22; h++)
	{
		hPos = h * 32;
		
		for (auto w = 0; w < 22; w++)
		{
			mainGame.getMapCell(h,w).getCellSprite()->sprite.setPosition(w * 32, hPos);
			//pass = std::to_string(mainGame.getMapCell(h, w).getPassability());
			text.setString(std::to_string(mainGame.getMapCell(h, w).getPassability()));
			text.setPosition(w * 32, hPos);
			target.draw(mainGame.getMapCell(h, w).getCellSprite()->sprite, states);
			target.draw(text, states);

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