#include "CactusClass.h"

CactusClass::CactusClass(Texture* pCC, RenderWindow& window, int x)
{
	if (pCC == nullptr) return;
	body.setTexture(*pCC);
	body.setScale(float(window.getSize().x / 4320.0f), float(window.getSize().y / 2160.0f));
	body.setPosition(window.getSize().x * x - 135.0f, 0.0f);
}

void CactusClass::Draw(RenderWindow& window)
{
	window.draw(body);
}
