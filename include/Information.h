#pragma once
#include "Command.h"
class Information : public Command
{
public:

	//========Constructor==========
	Information() = default;

	//========Virual functions==========
	virtual bool execute(sf::RenderWindow& window) override;
	virtual ~Information() =default;
private:
};
