#include "DataBar.h"
#include "Const.h"
#include "GameFont.h"
#include "GameTexture.h"
#include "InformationGame.h"

class TimeInformationBar : public DataBar{
public:
	TimeInformationBar(InformationGame& informationGame);
	~TimeInformationBar() = default;
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;
private:

	sf::Sprite m_clockSprite;
	sf::Text m_currentTimeAndTitle[TEXT_AND_DATA];

};

