#include "DataBar.h"
#include "Const.h"
#include "GameFont.h"
#include "GameTexture.h"
#include "InformationGame.h"

class TimeInformationBar : public DataBar
{
public:
	//=========Constructor============
	TimeInformationBar(InformationGame* informationGame);

	//=========Desstructor============
	~TimeInformationBar() = default;

	//==============Virtual functions================
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;


private:

	sf::Sprite m_clockSprite;
	sf::Text m_currentTimeAndTitle[TEXT_AND_DATA];

};

