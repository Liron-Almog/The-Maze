#include "GobletInformationBar.h"

GobletInformationBar::GobletInformationBar(InformationGame& informationGame) : DataBar(informationGame) {

	sf::IntRect temp;

	//sets goblet image
	m_gobeltltSprite.setTexture(*GameTexture::instance().getTexture(GOBLET));
	m_gobeltltSprite.setScale(0.32, 0.32);
	temp.width = m_gobeltltSprite.getTexture()->getSize().x / 8;
	temp.height = m_gobeltltSprite.getTexture()->getSize().y;
	m_gobeltltSprite.setTextureRect(temp);
	m_gobeltltSprite.setPosition(760, 690);

	//sets text
	m_numberOfGoblet.setCharacterSize(40);
	m_numberOfGoblet.setColor(sf::Color::White);
	m_numberOfGoblet.setFont(GameFont::instance().getFont(SHARPSHOTER_FONT));
	m_numberOfGoblet.setPosition(820, 690);

}
void GobletInformationBar::update(){

	m_numberOfGoblet.setString("x " + to_string(m_informationGame->getGobletCollected()));
}
void GobletInformationBar::draw(sf::RenderWindow& window){

	window.draw(m_gobeltltSprite);
	window.draw(m_numberOfGoblet);
}