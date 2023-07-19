#include "Start.h"

//The virtual function executes the start button 
//=============execute===========
bool Start::execute(sf::RenderWindow& window) {

	drawTransitionScreen(window);
	window.display();
	sleep(2);

	SingeltonSound::instance().pauseMusic(MENU_MUSIC);
	SingeltonSound::instance().playMusic(GAME_MUSIC);
	Controller game;
	game.run(window);
	SingeltonSound::instance().pauseMusic(GAME_MUSIC);

	//returns background to starting point
	return true;
}
//=============constructor===========
Start::Start() {

	m_transitionScreen.setTexture(*GameTexture::instance().getTransitionScreen(START_SCREEN));
	
}

