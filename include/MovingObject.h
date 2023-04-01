#pragma once
#include "GameObject.h"
class MovingObject :public GameObject
{
public:
	MovingObject ();
	~MovingObject ();
	virtual void updateAnimation(const float& s){};
private:

};

