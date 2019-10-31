#pragma once
#include <SFML/Graphics.hpp>

extern Settings g_settings;
//enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };


class Render : public sf::Drawable, public sf::Transformable
{
protected:
	sf::Font dfont;
	sf::Text dtext;
	int dfieldHeight;
	int dfieldWidth;
	int dtileCount;
	
public:
	Render();
	int GetFieldHeight() const;
	int GetFieldWidth() const;
	void SetText(std::string &text, float x, float y);
	void SetText(int text, float x, float y);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

/*sf::Font font;

std::string fps;
sf::Text text;
text.setCharacterSize(12);
text.setFont(font);
text.setPosition(static_cast<float>(wWidth) - 60.0f, 10.0f);
*/

