#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
public:
	//-----------------FUNKCJE-----------------------
	Player(Texture* pT); //konstruktur pT - playerTexture do za�adowania obrazka
	void Move(float deltaTime);
	void Jump();
	void Draw(RenderWindow& window);

	void Collide();
	Vector2f GetPosition() { return body.getPosition(); }
	float gravity = 1.0f;
	//-----------------ZMIENNE-----------------------
	bool onGround = true; //Zmienna do sprawdzania czy posta� dotyka pod�ogi
private:
	float movementSpeed = 500.0f;
	Sprite body; //Cia�o/posta� gracza - na tym wykonujemy wszystkie operacje typu przemieszczenie itp.
	Vector2f velocity {0,0}; //Zmienna do poruszania postaci� prawo/lewo (x) g�ra/d� (y)
	bool canJump = true;
	bool wantJump = false;
	float jumpHeight = 1500.0f;
};

