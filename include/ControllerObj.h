#pragma once
#include "MovingObject.h"
class ControllerObj : public MovingObject
{
public:
	ControllerObj();
	~ControllerObj();
	virtual void move(const sf::Vector2f& direction, const float& elapsedTime) = 0;
private:

};
