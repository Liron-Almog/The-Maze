#pragma once
#include "StaticObject.h"
#include "Animation.h"
#include "GameTexture.h"
class Coin : public StaticObject
{
public:

	//==============Constructor============
	Coin();

	//==============Destractor============
	~Coin() = default;

	//=================Virtual methods==================
	virtual void draw(sf::RenderWindow& window) override;

private:

	Animation m_coinAnimation = Animation(sf::Vector2i(8, 1), 0.25, *GameTexture::instance().getTexture(COIN));
		
};

