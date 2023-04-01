#pragma once
#include "DataBar.h"
#include "GameFont.h"
#include "GameTexture.h"

class GobletInformationBar : public DataBar
{
public:
	GobletInformationBar(InformationGame& informationGame);
	~GobletInformationBar () = default;
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;

private:
	sf::Sprite m_gobeltltSprite;
	sf::Text m_numberOfGoblet;

};
