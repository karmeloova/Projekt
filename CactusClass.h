#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class CactusClass
{
public:
	CactusClass(Texture* pCC, RenderWindow& window, int x);
	void Draw(RenderWindow& window);
	Sprite body;
};