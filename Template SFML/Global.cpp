#include "pch.h"
#include "Settings.h"
#include "Graphics.h"
#include <vector>
#include "Sprite.h"
#include "Actor.h"

Settings g_settings;
unsigned __int8 g_spriteSize = g_settings.GetSpriteSize();
Graphics g_gameGraphics("data/images/tileset/set_max.png");
sf::Texture g_mainTexture = g_gameGraphics.GetTexture();
//Sprite g_packMan(27, 94, g_spriteSize);
//Actor packMan(g_packMan);
//MapCell one(EARTH);


//Помощь

	/*
	std::cout << "bool:\t\t"		<< sizeof(bool)			<< " bytes" << std::endl;
	std::cout << "char:\t\t"		<< sizeof(char)			<< " bytes" << std::endl;
	std::cout << "wchar_t:\t"		<< sizeof(wchar_t)		<< " bytes" << std::endl;
	std::cout << "char16_t:\t"		<< sizeof(char16_t)		<< " bytes" << std::endl;
	std::cout << "char32_t:\t"		<< sizeof(char32_t)		<< " bytes" << std::endl;
	std::cout << "short:\t\t"		<< sizeof(short)		<< " bytes" << std::endl;
	std::cout << "int:\t\t"			<< sizeof(int)			<< " bytes" << std::endl;
	std::cout << "long:\t\t"		<< sizeof(long)			<< " bytes" << std::endl;
	std::cout << "long long:\t"		<< sizeof(long long)	<< " bytes" << std::endl;
	std::cout << "float:\t\t"		<< sizeof(float)		<< " bytes" << std::endl;
	std::cout << "double:\t\t"		<< sizeof(double)		<< " bytes" << std::endl;
	std::cout << "INT8_MIN  :\t"	<< "1 bytes\t"			<< INT8_MIN << std::endl;
	std::cout << "INT16_MIN :\t"	<< "2 bytes\t"			<< INT16_MIN << std::endl;
	std::cout << "INT32_MIN :\t"	<< "4 bytes\t"			<< INT32_MIN << std::endl;
	std::cout << "INT64_MIN :\t"	<< "8 bytes\t"			<< INT64_MIN << std::endl;
	std::cout << "INT8_MAX  :\t"	<< "1 bytes\t"			<< INT8_MAX << std::endl;
	std::cout << "INT16_MAX :\t"	<< "2 bytes\t"			<< INT16_MAX << std::endl;
	std::cout << "INT32_MAX :\t"	<< "4 bytes\t"			<< INT32_MAX << std::endl;
	std::cout << "INT64_MAX :\t"	<< "8 bytes\t"			<< INT64_MAX << std::endl;
	std::cout << "UINT8_MAX :\t"	<< "1 bytes\t"			<< UINT8_MAX << std::endl;
	std::cout << "UINT16_MAX:\t"	<< "2 bytes\t"			<< UINT16_MAX << std::endl;
	std::cout << "UINT32_MAX:\t"	<< "4 bytes\t"			<< UINT32_MAX << std::endl;
	std::cout << "UINT64_MAX:\t"	<< "8 bytes\t"			<< UINT64_MAX << std::endl;
	*/

	//int x = 2;
	//int *xRef = &x;
	//int y = *xRef + 2;
	//int *yRef;
	//

	/*
	 class One
	{
	protected:
		int dy=0;
	public:
		One() { dy = 0; };
		One(int y) { dy = y; };

		void SetY(int value) { dy = value; };
		int GetY() { return dy; }
	};
	One test(7);
	class Two
	{
	protected:
		One &dref;
		int x = 1;
	public:
		Two() :dref(*new One) {};
		Two(One& valueRef) : dref(valueRef) { dref = valueRef; };
		Two &operator=(Two &&right)
		{
			dref = right.dref;
			x = right.x;
			return *this;
		};

		One GetDref()
		{
			return dref;
		};
	};

	class Thre
	{
	protected:
		One *pOne = new One;
		int ds = 3;
	public:
		Thre() = default;
		Thre(One &oneRef)
		{
			pOne = &oneRef;
		};
		One &GetOne()
		{
			return *pOne;
		};
	};
	*/