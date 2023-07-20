#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Platforms
{
	public:
		Platforms(Vector2f Position, Texture* pP, bool moving); //Konstruktor do platformy, na kt�r� posta� skacze
		Platforms(Vector2f position, Vector2f size); //Konstruktor do platormy, po kt�rej posta� chodzi (ta br�zowa pod nogami)

		void Draw(RenderWindow& window);
		void MovingPlatform(float deltaTime);
		Sprite body; //Cia�o do platofrmy, na kt�r� posta� skacze
		RectangleShape bodyS; //Cia�o do tej br�zowej platformy
		bool movePlatform = false;
		int direction = 1;
		float platformSpeed = 0.1f; // Pr�dko�� przesuwania platformy (piksele na sekund�)
		float platformDistance = 200.0f; // Odleg�o��, na kt�r� platforma b�dzie si� przesuwa
		float startPositionX;
		

	private:
};	