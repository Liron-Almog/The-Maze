#pragma once
#include "DataBar.h"
#include "GameFont.h"
#include "GameTexture.h"

class CoinInformationBar : public DataBar
{
public:

	//==============Constructor============
	CoinInformationBar(InformationGame* informationGame);

	//==============Destractor============
	~CoinInformationBar () = default;

	//=================Virtual methods==================
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;

private:
	void setSettingPhoto();
	void setSettingText();
	sf::Sprite m_coinSprite;
	sf::Text m_numberOfCoins;

};
