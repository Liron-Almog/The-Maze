#include "TimeInformationBar.h"
#include <iostream>

//==========Constructor=========
TimeInformationBar::TimeInformationBar(InformationGame * informationGame) : DataBar(informationGame)
{
	//Defult setting
	for (int i = 0; i < TEXT_AND_DATA; i++) {
		m_currentTimeAndTitle[i].setCharacterSize(40);
		m_currentTimeAndTitle[i].setColor(sf::Color::White);
	}

	//sets text
	m_currentTimeAndTitle[TEXT].setFont(GameFont::instance().getFont(SHARPSHOTER_FONT));
	m_currentTimeAndTitle[TEXT].setString("Time: ");
	m_currentTimeAndTitle[TEXT].setPosition(330, 765);

	//sets data clock
	m_currentTimeAndTitle[DATA].setPosition(455, 765);
	m_currentTimeAndTitle[DATA].setFont(GameFont::instance().getFont(TIME_FONT));

	//sets clock photo
	m_clockSprite.setTexture(*GameTexture::instance().getTexture(CLOCK));
	m_clockSprite.setPosition(272, 765);
}
//==========update========
void TimeInformationBar::update(){  

	m_currentTimeAndTitle[DATA].setString(to_string(m_informationGame->getTime()));
}
//==========draw========
void TimeInformationBar::draw(sf::RenderWindow& window)  {

	for (int i = 0; i < TEXT_AND_DATA; i++)
		window.draw(m_currentTimeAndTitle[i]);

	window.draw(m_clockSprite);

}