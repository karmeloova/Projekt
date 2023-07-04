#include "Traps.h"

Traps::Traps(Vector2f Position, Texture* pT)
{
	body.setTexture(*pT);
	body.setPosition(Position);
}

void Traps::Draw(RenderWindow& window)
{
	window.draw(body);
}
