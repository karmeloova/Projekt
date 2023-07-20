#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platforms.h"
#include "Traps.h"
using namespace sf;
class Buttons
{
public:
	Buttons(Vector2f Position, Texture* pB, String buttonText, Vector2f pos);
	void Draw(RenderWindow& window);
	Sprite body;
	bool clickOnButton(RenderWindow& window, int offsetx, int offsety);

private: 
	Font buttonFont;
	Text* bT;
};