#include "Platforms.h"

Platforms::Platforms(Vector2f Position, Texture* pP, bool moving)
{
	body.setTexture(*pP);
	body.setPosition(Position);

	body.setScale(4, 4);
	if (moving) movePlatform = true;
	else movePlatform = false;
}

Platforms::Platforms(Vector2f position, Vector2f size)
{
	bodyS.setSize(size);
	bodyS.setFillColor(Color(193, 113, 42));
	bodyS.setPosition(position);
}


void Platforms::Draw(RenderWindow& window)
{
	window.draw(body);
	window.draw(bodyS);
}

