#pragma once

#include "Animation.h"
#include "MovingObject.h"
#include "RandomMove.h"

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
	Animation m_enemyAnim;
	static bool m_registerit;
};

