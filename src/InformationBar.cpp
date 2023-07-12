#include "InformationBar.h"
#include <iostream>

void InformationBar::draw(sf::RenderWindow& window) {


	for (int i = 0; i < m_dataBar.size(); i++) {
		m_dataBar[i]->update();
		m_dataBar[i]->draw(window);
	}

}
InformationBar::InformationBar(InformationGame * m_informationGame)
{

	m_dataBar.push_back(std::make_unique<TimeInformationBar>(m_informationGame));
	m_dataBar.push_back(std::make_unique<CoinInformationBar>(m_informationGame));
}

