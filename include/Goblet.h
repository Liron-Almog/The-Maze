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
	Animation m_gobletAnimation = Animation(sf::Vector2i(8, 1), 0.25, *GameTexture::instance().getTexture(GOBLET));
		
	
};

