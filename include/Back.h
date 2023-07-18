#pragma once
#include "Command.h"
class Back :public Command
{
public:

	//===========Constructor=============
	Back() = default;

	//=================Virtual methods==================
	virtual bool execute(sf::RenderWindow&);
	virtual ~Back() = default;
	
private:

};

