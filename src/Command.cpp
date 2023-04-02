#include "Command.h"
#include "Const.h"
#include "GameFont.h"
#include <chrono>
//---------setText---------------------
void Command::setText(const string& name, const sf::Vector2i& pos) {
	m_text.setString(name);
	m_text.setPosition(pos.x, pos.y);
}
//--------------Constructor--------------------
Command::Command() {
	//defult
	m_text.setColor(sf::Color::White);
	m_text.setFont(GameFont::instance().getFont(TITLE_FONT));
	m_text.setCharacterSize(55);
	m_text.setOutlineThickness(1);
	m_text.setOutlineColor(sf::Color::Black);

}
//-------------drawTransitionScreen---------------
void Command::drawTransitionScreen(sf::RenderWindow& window) {

	window.clear();
	window.draw(m_transitionScreen);

}
//---------------------sleep--------------------
void Command::sleep(const int & time) const {

	std::this_thread::sleep_for(std::chrono::seconds(time));
}
//---------------------getText------------------
 const sf::Text& Command::getText() const {

	return m_text;

}
