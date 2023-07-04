#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

Player::Player(Texture* pT)
{
	body.setPosition(0.0f, 467.0f); //Pozcyja pocz¹tkowa x = 0.0f, poniewa¿ postaæ ma startowaæ od lewej krawêdzi, y = 695.0f - ¿eby by³a w dolnym rogu czyli wysokoœæ ekranu pomniejszona o wysokoœæ obrazka
	body.setTexture(*pT);
	onGround == true;
}

void Player::Move(float deltaTime)
{

	velocity.x = 0.0f;
	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::W)) {
		velocity.x += movementSpeed;
	}
	//je¿eli wciœniemy A lub strza³kê w lewo oraz pozycja x bêdzie wiêksza od 0 (warunek aby postaæ nie wysz³a za krawêdŸ ekranu), to zmniejszaj wartoœæ wektora 2D (poruszaj siê w lewo)
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


