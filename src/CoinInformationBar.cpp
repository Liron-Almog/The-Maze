#include "CoinInformationBar.h"

//=================Constructor==============
CoinInformationBar::CoinInformationBar(InformationGame* informationGame) :DataBar(informationGame) {

	setSettingPhoto();
	setSettingText();
}
//==============setSettingPhoto==============
void CoinInformationBar::setSettingPhoto() {

	//sets coin image
	m_coinSprite.setTexture(*GameTexture::instance().getTexture(COIN));

	sf::IntRect temp;
	temp.width = m_coinSprite.getTexture()->getSize().x / NUM_OF_PHOTHS_IN_COIN_ANIMATION;
	temp.height = m_coinSprite.getTexture()->getSize().y;
	m_coinSprite.setTextureRect(temp);
	m_coinSprite.setPosition(760, 755);
}
//==============setSettingText==============
void CoinInformationBar::setSettingText() {

	m_numberOfCoins.setCharacterSize(40);
	m_numberOfCoins.setColor(sf::Color::White);
	m_numberOfCoins.setFont(GameFont::instance().getFont(SHARPSHOTER_FONT));
	m_numberOfCoins.setPosition(820, 765);
}
//==============update==============
void CoinInformationBar::update(){

	m_numberOfCoins.setString("x " + to_string(m_informationGame->getGobletCollected()));
}
//==============draw==============
void CoinInformationBar::draw(sf::RenderWindow& window){

	window.draw(m_coinSprite);
	window.draw(m_numberOfCoins);
}