#pragma once
#include "Const.h"
#include <memory>
#include <SFML/Graphics.hpp>
class GameFont

{
public:

	static GameFont& instance();
	~GameFont() = default;
	const sf::Font & getFont(const int& num) const;

private:

	GameFont();
	GameFont(const GameFont&) = default;
	GameFont& operator=(const GameFont&) = default;
	sf::Font m_fontGame[NUMBER_OF_FONT];
};

