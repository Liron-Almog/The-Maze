#include "CoinInformationBar.h"

CoinInformationBar::CoinInformationBar(InformationGame* informationGame) :DataBar(informationGame) {

	sf::IntRect temp;
	m_informationGame = informationGame;
	//sets goblet image
	m_coinSprite.setTexture(*GameTexture::instance().getTexture(COIN));
	m_coinSprite.setScale(0.92, 0.92);
	temp.width = m_coinSprite.getTexture()->getSize().x / 8;
	temp.height = m_coinSprite.getTexture()->getSize().y;
	m_coinSprite.setTextureRect(temp);
	m_coinSprite.setPosition(760, 690);

	//sets text
	m_numberOfGoblet.setCharacterSize(40);
	m_numberOfGoblet.setColor(sf::Color::White);
	m_numberOfGoblet.setFont(GameFont::instance().getFont(SHARPSHOTER_FONT));
	m_numberOfGoblet.setPosition(820, 690);

}
void CoinInformationBar::update(){

	m_numberOfGoblet.setString("x " + to_string(m_informationGame->getGobletCollected()));
}
void CoinInformationBar::draw(sf::RenderWindow& window){

	window.draw(m_coinSprite);
	window.draw(m_numberOfGoblet);
}