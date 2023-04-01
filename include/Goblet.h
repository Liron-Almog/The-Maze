#pragma once
#include "StaticObject.h"
#include "Animation.h"
#include "GameTexture.h"
class Goblet : public StaticObject
{
public:
	Goblet();
	~Goblet();

private:
	Animation m_gobletAnimation = Animation(*GameTexture::instance().getTexture(GOBLET)
		, sf::Vector2u(8, 1), 0.25);
};

