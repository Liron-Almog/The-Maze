#pragma once
#include "InformationBar.h"
class DataBar
{
public:
	DataBar(InformationGame & informationGame);
	~DataBar() = default;
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

protected :
	InformationGame* m_informationGame;
private:

};