#pragma once
#include "DataBar.h"
#include "GameFont.h"
#include "GameTexture.h"

class CoinInformationBar : public DataBar
{
public:

	CoinInformationBar(InformationGame* informationGame);
	~CoinInformationBar () = default;
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;

private:
	sf::Sprite m_coinSprite;
	sf::Text m_numberOfGoblet;

};
