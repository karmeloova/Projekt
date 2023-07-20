#include "Traps.h"

Traps::Traps(Vector2f Position, Texture* pT)
{
	if (pT == nullptr) return;
	body.setTexture(*pT);
	body.setPosition(Position);
}

void Traps::Draw(RenderWindow& window)
{
	window.draw(body);
}