#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platforms.h"
#include "Traps.h"
#include "Coins.h"
using namespace sf;
class Player
{
public:
	//-----------------FUNKCJE-----------------------
	Player(Texture* pT); //konstruktur pT - playerTexture do za³adowania obrazka
	void Move(float deltaTime, RenderWindow& window);
	void Jump();
	void Draw(RenderWindow& window);
	void Collide(std::vector<Platforms>* platforms, vector<Traps>* spikes, vector<Coins>* coins);
	void Restart();
	Vector2f GetPosition() { return body.getPosition(); }
	float gravity = 0.05f;
	//-----------------ZMIENNE-----------------------
	bool onGround = true; //Zmienna do sprawdzania czy postaæ dotyka pod³ogi
	Sprite body;
	int points = 0; //Zmienna do liczenia punktów
	int lives = 3;


private:
	float movementSpeed = 0.5f;
	Vector2f velocity {0,0}; //Zmienna do poruszania postaci¹ prawo/lewo (x) góra/dó³ (y)
	bool canJump = true;
	bool wantJump = false;
	float jumpHeight = 1.25f;
	Vector2f startPosition{ 30.0f, 400.0f };
};

