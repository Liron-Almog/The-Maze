#pragma
#include "DataBar.h"
#include "GameTexture.h"
#include "Const.h"
#include "InformationGame.h"
class InformationBar
{
public:

	InformationBar(InformationGame& informationGame);
	~InformationBar() = default;
	
	void draw(sf::RenderWindow& window);
private:

	vector<unique_ptr<DataBar>> m_dataBar;

	//void registerToDataBar(std::unique_ptr<DataBar> dataBar);


}; 

