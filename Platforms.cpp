#include "Platforms.h"

Platforms::Platforms(Vector2f Position, Texture* pP, bool moving)
{
    if (pP == nullptr) return;
	body.setTexture(*pP);
	body.setPosition(Position);
	body.setScale(4, 4);
    movePlatform = moving;
    if (movePlatform) {
        body.setOrigin(body.getGlobalBounds().width / 2, 0);
    }

    startPositionX = body.getPosition().x;
}

Platforms::Platforms(Vector2f position, Vector2f size)
{
    startPositionX = body.getPosition().x;
	bodyS.setSize(size);
	bodyS.setFillColor(Color(193, 113, 42));
	bodyS.setPosition(position);
}


void Platforms::Draw(RenderWindow& window)
{
	window.draw(body);
	window.draw(bodyS);
}

void Platforms::MovingPlatform(float deltaTime)
{
    if (body.getPosition().x < startPositionX - platformDistance || body.getPosition().x  > startPositionX + platformDistance) {
        direction = -direction;
    }
	
    body.move(platformSpeed*deltaTime*direction , 0.0f);
}