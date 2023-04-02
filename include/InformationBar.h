#pragma once
#include "InformationGame.h"
#include "Const.h"
#include "DataBar.h"
#include "TimeInformationBar.h"
#include "GobletInformationBar.h"
class InformationBar
{
public:
	InformationBar(InformationGame*);
	~InformationBar() = default;
	void draw(sf::RenderWindow& window);
private:

	vector<unique_ptr<DataBar>> m_dataBar;

};

