#include "InformationGame.h"
#include <iostream>

//=========setTime===========
void InformationGame::setTime(const int& currentTime) {
	m_currentTime = currentTime;
}

//=========getTime===========
int InformationGame::getTime() const {

	return m_currentTime;
}
//=========setGobletCollected===========
void InformationGame::setCoinCollected(const unsigned& goblets) {
	m_gobletCollected = goblets;
}

//=========getGobletCollected===========
unsigned InformationGame::getGobletCollected() const {
	return m_gobletCollected;
}