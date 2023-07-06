#include "Buttons.h"

Buttons::Buttons(Vector2f Position, Texture* pB)
{
	body.setTexture(*pB);
	body.setPosition(Position);
	body.setScale(0.35, 0.35);
	
}

void Buttons::Draw(RenderWindow& window, String buttonText, Vector2f pos)
{
	buttonFont.loadFromFile("Fonts/consola.ttf");
	Text bT(buttonText, buttonFont, 35);
	bT.setPosition(pos);
	window.draw(body);
	window.draw(bT);
}

void Buttons::clickOnButton(RenderWindow& window)
{
	Vector2i mousePos = Mouse::getPosition(window);
	Vector2f buttonPosition = body.getPosition();
	Vector2f buttonSize(body.getGlobalBounds().width, body.getGlobalBounds().height);

	FloatRect buttonBounds(buttonPosition, buttonSize);

	if (body.getGlobalBounds().contains(mousePos.x, mousePos.y))
	{
		cout << "NAJECHALES NA PRZYCISK";
		if (Mouse::isButtonPressed(Mouse::Left)) {
			std::cout << "KLIKNIÊCIE W PRZYCISK" << std::endl;
		}
	}
}


