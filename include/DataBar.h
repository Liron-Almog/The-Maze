#pragma once
#include "InformationGame.h"
#include "Const.h"
class DataBar
{
public:
	DataBar(InformationGame * InformationGame);
	~DataBar() = default;
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

protected:
	InformationGame* m_informationGame;
private:

};