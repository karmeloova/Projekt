#include "Buttons.h"

Buttons::Buttons(Vector2f Position, Texture* pB, String buttonText, Vector2f pos)
{
	if (pB == nullptr) return;
	body.setTexture(*pB);
	body.setPosition(Position);
	body.setScale(0.35, 0.35);
	buttonFont.loadFromFile("Fonts/consola.ttf");
	bT = new Text(buttonText, buttonFont, 35);
	bT->setPosition(pos);
}


void Buttons::Draw(RenderWindow& window)
{
	window.draw(body);
	window.draw(*bT);
}

bool Buttons::clickOnButton(RenderWindow& window, int offsetx, int offsety)
{
	Vector2i mousePos = Mouse::getPosition(window);

	Vector2f buttonPosition = body.getPosition();
	Vector2f buttonSize(body.getGlobalBounds().width, body.getGlobalBounds().height);

	FloatRect buttonBounds(buttonPosition, buttonSize);

	if (body.getGlobalBounds().contains(mousePos.x-offsetx, mousePos.y-offsety)) //minus przesuniêcie widoku
	{
		if (Mouse::isButtonPressed(Mouse::Left)) {
			return true;
		}
		return false;
	}
	return false;
}