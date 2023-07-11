#pragma once
#include "MoveBehavior.h"
class StriteMove : public MoveBehavior
{
public:
	StriteMove() = default;
	~StriteMove() = default;
	virtual void moveObject(MovingObject&) override;
private:

};

