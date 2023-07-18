#pragma once
#include "Animation.h"
#include "MovingObject.h"
#include "RandomMove.h"
#include "GameTexture.h"

class Enemy : public MovingObject
{
public:

	//==============virtual functions============
	virtual void move(const float&) override;
	void changeDirection();


	//===============Constructor===========
	Enemy ();

	//===========Destructor============
	~Enemy () = default;

	void moveBack();

private:

	Animation m_enemyAnimation = Animation(sf::Vector2i(3, 4), 0.25, *GameTexture::instance().getTexture(ENEMY));
	static bool m_registerit;
};

