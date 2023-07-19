#include "GameTime.h"
//The function Initializes the clock
//======startTime=========
void GameTime::startTime() {
    
    m_totalTime = GAME_TIME;
    m_gameTime.restart();

}
//======getTime=========
int GameTime::getTime() const {
    
    return m_totalTime - (int)m_gameTime.getElapsedTime().asSeconds();

}
