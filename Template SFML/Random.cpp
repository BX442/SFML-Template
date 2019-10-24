#include "pch.h"
#include "Random.h"
#include <iostream>

int f() {
	std::random_device dev;
	std::mt19937 engine(dev());

	return engine();
}