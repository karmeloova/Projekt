#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Platforms
{
	public:
		Platforms(Vector2f Position, Texture* pP, bool moving); //Konstruktor do platformy, na któr¹ postaæ skacze
		Platforms(Vector2f position, Vector2f size); //Konstruktor do platormy, po której postaæ chodzi (ta br¹zowa pod nogami)

		void Draw(RenderWindow& window);
		void MovingPlatform(float deltaTime);
		Sprite body; //Cia³o do platofrmy, na któr¹ postaæ skacze
		RectangleShape bodyS; //Cia³o do tej br¹zowej platformy
		bool movePlatform = false;
		int direction = 1;
		float platformSpeed = 0.1f; // Prêdkoœæ przesuwania platformy (piksele na sekundê)
		float platformDistance = 200.0f; // Odleg³oœæ, na któr¹ platforma bêdzie siê przesuwa
		float startPositionX;
		

	private:
};	