#pragma once
#include "StaticObject.h"
#include "Factory.h"
#include "GameTexture.h"
#include "Const.h"
class Wall : public StaticObject
{
public:
	Wall();
	~Wall() = default;
	void updateAnimation(const float&){}//ignore

private:

};

