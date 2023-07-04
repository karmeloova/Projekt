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
	body.setPosition(0.0f, 467.0f); //Pozcyja pocz¹tkowa x = 0.0f, poniewa¿ postaæ ma startowaæ od lewej krawêdzi, y = 695.0f - ¿eby by³a w dolnym rogu czyli wysokoœæ ekranu pomniejszona o wysokoœæ obrazka
	body.setTexture(*pT);
	onGround = true;
	body.setOrigin(73/2, 0.f);
}


void Player::Move(float deltaTime)
{

	velocity.x = 0.0f;
	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::W)) {
		velocity.x += movementSpeed;
		body.setScale(1.f, 1.f);
	}
	//je¿eli wciœniemy A lub strza³kê w lewo oraz pozycja x bêdzie wiêksza od 0 (warunek aby postaæ nie wysz³a za krawêdŸ ekranu), to zmniejszaj wartoœæ wektora 2D (poruszaj siê w lewo)
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
	//cout << body.getPosition().y << " "<<"Czy ziemia: "<<onGround<<endl;
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

	if (body.getPosition().y >= 467.0f) {
		onGround = true;
	}
	else {
		for (int i = 0; i < platforms->size(); i++) {
			if (body.getGlobalBounds().intersects(platforms->at(i).body.getGlobalBounds())) {
				onGround = true;
				return;
			}
		}

		onGround = false;
	}

	for (int i = 0; i < coins->size(); i++) {
		if (body.getGlobalBounds().intersects(coins->at(i).body.getGlobalBounds()) && coins->at(i).isAlive == true) {
			points++;
			cout << points << endl;
			coins->at(i).isAlive = false;
		}
	}

}

void Player::Restart()
{
	body.setPosition(0.0f, 467.0f);
}





//sprite.getGlobalBounds().intersects(sprite2.getGlobalBounds)