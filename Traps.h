#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Traps
{

	public:
		Traps(Vector2f Position, Texture* pT);
		void Draw(RenderWindow& window);

	private:
		Sprite body;
};

