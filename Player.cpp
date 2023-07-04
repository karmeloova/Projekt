#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

Player::Player(Texture* pT)
{
	body.setPosition(0.0f, 467.0f); //Pozcyja pocz�tkowa x = 0.0f, poniewa� posta� ma startowa� od lewej kraw�dzi, y = 695.0f - �eby by�a w dolnym rogu czyli wysoko�� ekranu pomniejszona o wysoko�� obrazka
	body.setTexture(*pT);
	onGround == true;
}

void Player::Move(float deltaTime)
{

	velocity.x = 0.0f;
	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::W)) {
		velocity.x += movementSpeed;
	}
	//je�eli wci�niemy A lub strza�k� w lewo oraz pozycja x b�dzie wi�ksza od 0 (warunek aby posta� nie wysz�a za kraw�d� ekranu), to zmniejszaj warto�� wektora 2D (poruszaj si� w lewo)
	if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && body.getPosition().x > 0) {
		velocity.x -= movementSpeed;
	}

	if (onGround) {
		velocity.y = 0;
	}
	else {
		velocity.y += gravity;
	}


	body.move(velocity * deltaTime);
	cout << body.getPosition().y << " "<<endl;
}

void Player::Jump() {

	if (Keyboard::isKeyPressed(Keyboard::Space) && onGround) {
		velocity.y -= jumpHeight;
		onGround = false;
	}

}

void Player::Draw(RenderWindow& window)
{
	window.draw(body);
}



void Player::Collide()
{
	if (body.getPosition().y >= 467.0f) {
		onGround = true;
	}
	else {
		onGround = false;
	}
}


