#include "Player.h"
#include "Platforms.h"
#include "Traps.h"
#include "Coins.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;
using namespace std;

Player::Player(Texture* pT)
{
	if (pT == nullptr) return;
	body.setPosition(startPosition); //Ustaw gracza na pozycji pocz�tkowej 
	body.setTexture(*pT); //Za�aduj tekstur� gracz (pT - playerTexture)
	onGround = false; //Ustaw, �e posta� nie jest na ziemi
	body.setOrigin(73/2, 0.f); //Powoduje, �e posta� nie przesuwa si� w prawo/lewo podczas zmiany kierunku chodzenia (obrotu postaci) - takie przytwierdznie
}


void Player::Move(float deltaTime, RenderWindow& window)
{

	velocity.x = 0.0f;
	if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && body.getPosition().x < 5142) {
		velocity.x += movementSpeed;
		body.setScale(1.f, 1.f);
	}
	//Sterowanie w lewo, body.getPosition().x > 0 - �eby nie wysz�a poza kraw�d� po prawej stronie
	if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && body.getPosition().x > 0) {
		velocity.x -= movementSpeed;
		body.setScale(-1.f, 1.f);
	}

	if (onGround) {
		velocity.y = 0;
	}
	else {
		velocity.y += gravity;
	}


	body.move(velocity * deltaTime);

}

void Player::Jump() {

	if (Keyboard::isKeyPressed(Keyboard::Space) && onGround) {
		velocity.y = -jumpHeight;
		onGround = false;
	}

}

void Player::Draw(RenderWindow& window)
{
	window.draw(body);
}


void Player::Collide(vector<Platforms>* platforms, vector<Traps>* spikes, vector<Coins>* coins)
{
	FloatRect playerFeet = body.getGlobalBounds();  // Koordynata y st�p gracza
	for (int i = 0; i < platforms->size(); i++) {
		FloatRect platformBoundsS = platforms->at(i).bodyS.getGlobalBounds();
		if (playerFeet.intersects(platformBoundsS) && playerFeet.top + 55.0f <= platformBoundsS.top) {
			onGround = true;
			return;
		}
		else {
			for (int i = 0; i < platforms->size(); i++) {
				FloatRect platformBounds = platforms->at(i).body.getGlobalBounds();
				if (playerFeet.intersects(platformBounds) && playerFeet.top+55.0f <= platformBounds.top) {
					onGround = true;
					return;
				}
		}
		onGround = false;
	}
	}

	for (int i = 0; i < coins->size(); i++) {
		if (body.getGlobalBounds().intersects(coins->at(i).body.getGlobalBounds()) && coins->at(i).isAlive == true) {
			points++;
			coins->at(i).isAlive = false;
		}
	}

}

void Player::Restart()
{
	body.setPosition(startPosition);
}