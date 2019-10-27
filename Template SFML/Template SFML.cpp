// Template SFML.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Render.h"
#include "Actor.h"

//TODO:Инициализация карты в Game.cpp и передача в рендер

using std::cout;
using std::endl;


int main()
{
	///Settings
	system("color 80");
	setlocale(LC_ALL, "");
	///Parametrs
	sf::RenderWindow window(sf::VideoMode(g_settings.GetWidth(), g_settings.GetHeight()), "Template SFML");
	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	time_t currentTime;
	time(&currentTime);
	srand(static_cast<int>(currentTime)); ///cout << currentTime << endl;

	//Start
	//sf::Image tileSet;
	//tileSet.loadFromFile("data/images/tileset/set_max.png");
	//
	//sf::Texture mainTexture;
	//mainTexture.loadFromImage(tileSet);
	//tileSet.~Image();
	//
	//Test spprite(g_mainTexture);
	
	//sf::Sprite testSprite;
	//testSprite.setTexture(g_mainTexture);
	//testSprite.setTextureRect(sf::IntRect(11 * g_spriteSize, 9 * g_spriteSize, g_spriteSize, g_spriteSize));
	//testSprite.setPosition(0, 0);

	extern Sprite g_packMan;
	extern Actor packMan;

	Render test;
	//sf::Clock clock;
	while (window.isOpen())
	{
		double start = clock();
		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) // Имитация задержки срабатывания
			{
				/// Получаем нажатую клавишу - выполняем соответствующее действие
				//if (event.key.code == sf::Keyboard::Numpad4) { testSprite.move(-1.0f, 0); }
				//if (event.key.code == sf::Keyboard::Numpad6) { testSprite.move(1.0f, 0); }
				//if (event.key.code == sf::Keyboard::Numpad8) { testSprite.move(0, -1.0f); }
				//if (event.key.code == sf::Keyboard::Numpad2) { testSprite.move(0, 1.0f); }
				if (event.key.code == sf::Keyboard::Escape) window.close();
			}
		}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) { testSprite.move(-0.4f, 0); } //первая координата Х отрицательна =>идём влево
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) { testSprite.move(0.4f, 0); } //первая координата Х положительна =>идём вправо
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) { testSprite.move(0, -0.4f); } //вторая координата (У) отрицательна =>идём вверх (вспоминаем из предыдущих уроков почему именно вверх, а не вниз)
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) { testSprite.move(0, 0.4f); } //вторая координата (У) положительна =>идём вниз (если не понятно почему именно вниз - смотрим предыдущие уроки)
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { window.close(); }

		//TODO:Что то в собсвтенном класе спрайта не так, он не отдаёт картинку
		
		window.clear();
		window.draw(test);
		//window.draw(packMan.getActorSprite()->getSprite());
		//window.draw(g_packMan.getSprite());
		//window.draw(spprite.getSprite());
		//window.draw(sprite);
		//window.draw(text);
		window.display();
		double end = clock();
		double seconds = (end - start) / CLOCKS_PER_SEC;
		//fps = std::to_string(seconds);
		//cout << f() << endl;
		if (seconds > 0.017f)
		{
			cout << "Отклонения: " << seconds /*<< "\tШтамп: " << clock() */ << endl;
		}
	}
}


//sf::Clock clock; //Таймер стартует сейчас	//Time elapsed = clock.restart(); //Возвращает время пройденое с предыдущего рестарта(или старта)//cout << "Время отрисовки: " << clock.restart().asMilliseconds() << endl; //sf::Time elapsed = clock.restart();// std::cout << "Время отрисовки: " << clock.restart().asMilliseconds() << std::endl;
/*
clock_t start = clock();
//code...
clock_t end = clock();
double seconds = (double)(end - start) / CLOCKS_PER_SEC;
std::cout << "Время выполнения: " << seconds << std::endl;
*/




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
