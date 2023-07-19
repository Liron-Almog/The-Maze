#pragma once
#include "Command.h"
class Quit : public Command
{
public:


	//=========Constructor============
	Quit();

	//=========Virtual functions==============
	virtual ~Quit() = default;
	bool execute(sf::RenderWindow& window) override;

private:
	
};

