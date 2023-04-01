
#include "GameFont.h"
#include "Const.h"
//-------------------instance--------------------
GameFont& GameFont::instance() {
	static GameFont inst;
	return inst;
}
//----------------getFont-----------------------
const sf::Font& GameFont::getFont(const int & num) const {

	return m_fontGame[num];
}
//----------------constructor-------------------
GameFont::GameFont() {

	m_fontGame[TITLE_FONT].loadFromFile("BubbleboddyExtralight-z54X.ttf");
	m_fontGame[CANDY_FONT].loadFromFile("Candy_Pop!-demo-font.ttf");
	m_fontGame[SHARPSHOTER_FONT].loadFromFile("Sharpshooter.ttf");
	m_fontGame[TIME_FONT].loadFromFile("TimeFont.ttf");
	
}

