#include "TimeInformationBar.h"
#include <iostream>
TimeInformationBar::TimeInformationBar(InformationGame * informationGame) : DataBar(informationGame)
{


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

void TimeInformationBar::update(){  

	m_currentTimeAndTitle[DATA].setString(to_string(m_informationGame->getTime()));
}
void TimeInformationBar::draw(sf::RenderWindow& window)  {

	for (int i = 0; i < TEXT_AND_DATA; i++)
		window.draw(m_currentTimeAndTitle[i]);

	window.draw(m_clockSprite);

}