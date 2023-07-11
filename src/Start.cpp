#include "Start.h"

//The virtual function executes the start button 
//-----------execute-------------
bool Start::execute(sf::RenderWindow& window) {

	drawTransitionScreen(window);
	window.display();
	sleep(2);

	Controller game;
	game.run(window);
	
	//returns background to starting point
	return true;
}
//-----------constructor-------------
Start::Start() {

	m_transitionScreen.setTexture(*GameTexture::instance().getTransitionScreen(START_SCREEN));
	
}

