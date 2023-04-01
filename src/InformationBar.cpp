#include "InformationBar.h"
#include "Goblet.h"
#include "GameFont.h"
InformationBar::InformationBar()
{
	setSettingOfGoblet();
	setSettingOfTime();	
}


void InformationBar::setSettingOfTime() {

	for (int i = 0; i < TEXT_AND_DATA; i++) {
		m_currentTimeAndTitle[i].setCharacterSize(40);
		m_currentTimeAndTitle[i].setColor(sf::Color::White);
	}

	//sets text
	m_currentTimeAndTitle[TEXT].setFont(GameFont::instance().getFont(SHARPSHOTER_FONT));
	m_currentTimeAndTitle[TEXT].setString("Time: ");
	m_currentTimeAndTitle[TEXT].setPosition(350, 690);

	//sets data clock
	m_currentTimeAndTitle[DATA].setPosition(475, 690);
	m_currentTimeAndTitle[DATA].setFont(GameFont::instance().getFont(TIME_FONT));

	//sets clock photo
	m_clockSprite.setTexture(*GameTexture::instance().getTexture(CLOCK));
	m_clockSprite.setPosition(292, 690);

}
void InformationBar::setSettingOfGoblet() {


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
void InformationBar::updateData(const unsigned& TheGobletCollected, const int& time) {

	m_numberOfGoblet.setString("x " + to_string(TheGobletCollected));
	m_currentTimeAndTitle[DATA].setString(to_string(time));
}
void InformationBar::drawInformationBar(sf::RenderWindow & window, const unsigned & TheGobletCollected, const int & time) {
	
	updateData(TheGobletCollected, time);
	for (int i = 0; i < TEXT_AND_DATA; i++) 
		window.draw(m_currentTimeAndTitle[i]);

	window.draw(m_gobeltltSprite);
	window.draw(m_numberOfGoblet);
	window.draw(m_clockSprite);

}