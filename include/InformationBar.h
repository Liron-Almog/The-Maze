#pragma

#include "GameTexture.h"
#include "Const.h"
class InformationBar
{
public:


	InformationBar();
	~InformationBar() = default;

	void drawInformationBar(sf::RenderWindow & , const unsigned&, const int&);
private:

	void setSettingOfTime();
	void updateData(const unsigned& level, const int& time);
	void setSettingOfGoblet();
	sf::Sprite m_gobeltltSprite,
				m_clockSprite;
	sf::Text m_currentTimeAndTitle[TEXT_AND_DATA];
	sf::Text m_numberOfGoblet;

}; 

