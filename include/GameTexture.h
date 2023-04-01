#pragma once
#include "Const.h"

class GameTexture
{
public:

	//------------------get function-------------------
	~GameTexture() = default;

	const sf::Texture* getBackgroundGame() const;
	const sf::Texture* getBackground(const int& num) const;
	static GameTexture& instance();
	const sf::Texture* getTexture(const int&) const;
	const sf::Texture* getTransitionScreen(const int& num) const;
	const sf::Texture* getBG(const int&) const {

		return nullptr;
	}

private:

	GameTexture();
	GameTexture(const GameTexture&) = default;
	GameTexture& operator=(const GameTexture&) = default;
	sf::Texture m_background[NUMBER_OF_BACKGROUND];
	sf::Texture m_objectTexture[NUMBER_OF_OBJECT];
	sf::Texture m_transitionScreens[NUMBER_OF_TRANSITION_SCREENS];
	sf::Texture m_backgroundGame;

};
