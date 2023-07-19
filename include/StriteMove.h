#pragma once
#include "MoveBehavior.h"
class StriteMove : public MoveBehavior
{
public:

	//=========Constructor============
	StriteMove() = default;

	//=========Desstructor============
	~StriteMove() = default;

	//==============Virtual functions================
	virtual void moveObject(MovingObject&) override;

private:

};

