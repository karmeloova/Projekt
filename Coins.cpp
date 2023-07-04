#include "Coins.h"

Coins::Coins(Vector2f Position, Texture* pC)
{
	body.setTexture(*pC);
	body.setPosition(Position);
	body.setScale(0.08, 0.08);
}

void Coins::Draw(RenderWindow& window)
{
	if(isAlive) window.draw(body);
}
