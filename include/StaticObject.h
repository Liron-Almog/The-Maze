#pragma once
#include "GameObject.h"
class StaticObject : public GameObject
{
public:

	StaticObject() = default;
	~StaticObject() = default;
	void updateAnimation(const float& a) {};

private:

};
