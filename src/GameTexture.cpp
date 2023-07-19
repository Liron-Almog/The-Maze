#include "const.h"
#include "GameTexture.h"
#include <SFML/Graphics.hpp>
//=============constructor==========
GameTexture::GameTexture()
{

	//Loading background screens
	loadingTransitionScreens();
	loadingBackground();
	loadingObjects();

}
//==============loadingTransitionScreens===============
void GameTexture::loadingTransitionScreens() {

	m_transitionScreens[GAME_OVER_SCREEN].loadFromFile("GameOver.jpg");
	m_transitionScreens[TIME_IS_OUT_SCREEN].loadFromFile("TimeIsOver.jpg");
	m_transitionScreens[QUIT_SCREEN].loadFromFile("Quit.png");
	m_transitionScreens[START_SCREEN].loadFromFile("Start.png");

}
//==============loadingBackgronds===============
void GameTexture::loadingBackground() {

	m_background[INFO_BACKGROUND].loadFromFile("Information.png");
	m_background[MENU_BACKGROUND].loadFromFile("MenuBackground.png");
	m_background[GAME_BACKGROUND].loadFromFile("BackgroundGame.png");

}
//==============loadingObjects===============
void GameTexture::loadingObjects(){

	m_objectTexture[PLAYER].loadFromFile("Player.png");
	m_objectTexture[WALL].loadFromFile("Wall.png");
	m_objectTexture[COIN].loadFromFile("CoinAnimation.png");
	m_objectTexture[DOOR].loadFromFile("Door.png");
	m_objectTexture[EMPTY].loadFromFile("Empty.png");
	m_objectTexture[ENEMY].loadFromFile("EnemyAnimation.png");
	m_objectTexture[SQUARE_INSIDE_SQUARE].loadFromFile("SquareInsideSquare.png");
	m_objectTexture[CLOCK].loadFromFile("Clock.png");
	m_objectTexture[LIGHTNING].loadFromFile("lightning.png");

}
//=============getBackground==========
const sf::Texture* GameTexture::getBackground(const int & num) const {

	return &m_background[num];

}
//=============getTransitionScreen==========
const sf::Texture* GameTexture::getTransitionScreen(const int& num) const {

	return &m_transitionScreens[num];

}
//=============getTexture==========
const sf::Texture* GameTexture::getTexture(const int & num) const {

	return &m_objectTexture[num];

}
//=============instance==========
GameTexture& GameTexture::instance() {
	static GameTexture inst;
	return inst;
}
