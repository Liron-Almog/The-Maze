#include "Quit.h"
#include "GameTexture.h"

//The virtual function executes the quit button in the menu 
//==============execute===============
bool Quit::execute(sf::RenderWindow& window) {

	drawTransitionScreen(window);
	window.display();
	sleep(2);
	exit(EXIT_SUCCESS);

	return false;//for compailer 
}
//==============costructor===============
Quit::Quit() {

	m_transitionScreen.setTexture(*GameTexture::instance().getTransitionScreen(QUIT_SCREEN));

} 
