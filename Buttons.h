#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platforms.h"
#include "Traps.h"
using namespace sf;
class Buttons
{
public:
	Buttons(Vector2f Position, Texture* pB);
	void Draw(RenderWindow& window, String buttonText, Vector2f pos);
	Sprite body;
	void clickOnButton(RenderWindow& window);

private: 
	Font buttonFont;
};

