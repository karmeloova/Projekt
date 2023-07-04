#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Platforms
{
	public:
		Platforms(Vector2f Position, Texture* pP);
		void Draw(RenderWindow& window);

	private:
		Sprite body;
};	

