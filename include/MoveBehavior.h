#pragma once

#include <SFML/Graphics.hpp>
class MovingObject;
class MoveBehavior
{
public:
	MoveBehavior() = default;
	virtual ~MoveBehavior() = default;
	virtual void moveObject(MovingObject&) = 0;

private:

};

