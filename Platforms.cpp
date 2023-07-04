#include "Platforms.h"

Platforms::Platforms(Vector2f Position, Texture* pP)
{
	body.setTexture(*pP);
	body.setPosition(Position);
	body.setScale(4, 4);
}

void Platforms::Draw(RenderWindow& window)
{
	window.draw(body);
}
