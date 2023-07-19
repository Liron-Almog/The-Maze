#include "Menu.h"
#include "GameFont.h"
#include "Const.h"
#include "GameTexture.h"
#include "Information.h"
#include "Quit.h"
#include "Start.h"

//The function adds button to the menu
//=============add================
void Menu::add(string name, unique_ptr<Command> button, sf::Vector2i pos) {

	m_options.emplace_back(option(name, move(button)));
	m_options[m_options.size() - 1].second->setText(name,pos);
}

//===========draw=============
void Menu::draw(sf::RenderWindow &window)const {

	window.clear();
	window.draw(m_background);
	window.draw(m_title);
	drawOption(window);
	window.display();
}
//=========drawOption=========
void Menu::drawOption(sf::RenderWindow&  window) const {

	for (size_t i = 0; i < m_options.size(); i++)
		window.draw(m_options[i].second->getText());

}
//Boolean function that returns true if after the operation 
// we want to exit the current menu,
//else continues to display the current menu
//=========performAction=========
bool Menu::performAction(const int & option , sf::RenderWindow& window) const{

	bool temp;
	if (option != -1) {
		//GameSound::instance().soundEffects(SELECT_SOUND);
		temp = m_options[option].second->execute(window);// executes the
														//button pressed
		draw(window);
		return temp;
	}
	return true;
}
//=========Consructor=========
Menu::Menu(const sf::Texture & BackGround, const string title,const sf::Color color) {
	
	m_title.setFont(GameFont::instance().getFont(SHARPSHOTER_FONT));
	m_title.setColor(color);
	m_title.setString(title);
	m_title.setCharacterSize(95);
	m_title.setPosition(SCREEN_W / 2 -430, SCREEN_H / 2 -250 );
	m_background.setTexture(BackGround);
	m_title.setOutlineThickness(2.5);
	m_title.setOutlineColor(sf::Color::Black);
}
//The function checks if user pressed on button from menu
//and then returns the number of button else returns - 1
//=========optionFromUser=========
int Menu::optionFromUser(sf::Event event, sf::RenderWindow& window) const {

	//checks if user choose an option
	for (size_t i = 0; i < m_options.size(); i++)
		if (m_options[i].second->getText().getGlobalBounds().contains(window.mapPixelToCoords
		({ event.mouseButton.x,event.mouseButton.y })))
			return i;

	return NO_OPTION;
}
//The function listens to pressed of user and 
// doing the wanted operation
//==========activate==============
void Menu::activate(sf::RenderWindow& window) {

	sf::Event event;
	int option ;

	do {
		option = NO_OPTION;
		while (window.pollEvent(event)) {

			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) &&
					(event.key.code == sf::Keyboard::Escape))) {
				window.close();
				exit(EXIT_SUCCESS);
			}

			if (sf::Event::MouseButtonPressed == event.type)
				option = optionFromUser(event, window);

			changeCursorIfOnButton(sf::Mouse::getPosition(window), window);
		}
		
	}
		while (performAction(option, window));
}
//The function chckes if the mouse stands on  one of buutons,
// then replaces the arrow cursor to hand ,else replaces to arrow. 
//==========changeCursorIfOnButton==============
void Menu::changeCursorIfOnButton(const sf::Vector2i pos, sf::RenderWindow& window) const{

	sf::Cursor arrow;
	sf::Cursor cursor;
	arrow.loadFromSystem(sf::Cursor::Arrow);
	cursor.loadFromSystem(sf::Cursor::Hand);

	//checks if the cursor stands on one of button
	for (size_t i = 0; i < m_options.size(); i++) {
		sf::Vector2i cursorPos = sf::Mouse::getPosition(window);
		if (m_options[i].second->getText().getGlobalBounds().contains(window.mapPixelToCoords
		({ cursorPos.x,cursorPos.y }))) {
			window.setMouseCursor(cursor);
			break;
		}
		else window.setMouseCursor(arrow);
	}
}

