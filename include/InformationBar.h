#pragma once
#include "InformationGame.h"
#include "Const.h"
#include "DataBar.h"
#include "TimeInformationBar.h"
#include "CoinInformationBar.h"
class InformationBar
{
public:

	//========Constructor==========
	InformationBar(InformationGame*);

	//========Destructor==========
	~InformationBar() = default;

	void draw(sf::RenderWindow& window);
private:

	vector<unique_ptr<DataBar>> m_dataBar;

};

