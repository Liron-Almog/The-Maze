#pragma once

#include <SFML/Graphics.hpp>
class MovingObject;
class MoveBehavior
{
public:

	//=======Constructor==============
	MoveBehavior() = default;

	//========Virtual functions===========
	virtual ~MoveBehavior() = default;
	virtual void moveObject(MovingObject&) = 0;

private:

};

