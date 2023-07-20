#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platforms.h"
#include "Traps.h"
using namespace sf;
class Coins
{
	public:
		Coins(Vector2f Position, Texture* pC);
		void Draw(RenderWindow& window);
		Sprite body;
		bool isAlive = true;
};