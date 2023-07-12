#include "const.h"
#include "GameTexture.h"
#include <SFML/Graphics.hpp>
//------------------constructor----------------
GameTexture::GameTexture()
{
	

	m_background[INFO_BACKGROUND].loadFromFile("Information.png");
	m_background[MENU_BACKGROUND].loadFromFile("MenuBackground.png");
	m_objectTexture[PLAYER].loadFromFile("Player.png");
	m_objectTexture[WALL].loadFromFile("Wall.png");
	m_objectTexture[COIN].loadFromFile("CoinAnimation.png");
	m_objectTexture[DOOR].loadFromFile("Door.png");
	m_objectTexture[LOADING].loadFromFile("Loading.png");
	m_objectTexture[EMPTY].loadFromFile("Empty.png");
	m_objectTexture[ENEMY].loadFromFile("EnemyAnimation.png");
	m_objectTexture[COMPUTER_PLAYER].loadFromFile("ComputerPlayer.png");
	m_transitionScreens[QUIT_SCREEN].loadFromFile("Quit.png");
	m_objectTexture[SQUARE_INSIDE_SQUARE].loadFromFile("SquareInsideSquare.png");
	m_transitionScreens[START_SCREEN].loadFromFile("Start.png");
	m_objectTexture[CLOCK].loadFromFile("Clock.png");
	m_backgroundGame.loadFromFile("BackgroundGame.png");



	//m_playersTexture[KEY].loadFromFile("Key.png");

}

//--------------getTexturePassScreen-----------
const sf::Texture* GameTexture::getBackground(const int & num) const {

	return &m_background[num];

}
const sf::Texture* GameTexture::getTransitionScreen(const int& num) const {

	return &m_transitionScreens[num];

}

const sf::Texture* GameTexture::getBackgroundGame() const {

	return &m_backgroundGame;

}

const sf::Texture* GameTexture::getTexture(const int & num) const {

	return &m_objectTexture[num];

}
//------------------instance-----------------
GameTexture& GameTexture::instance() {
	static GameTexture inst;
	return inst;
}
