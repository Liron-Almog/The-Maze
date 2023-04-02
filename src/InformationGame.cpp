#include "InformationGame.h"
#include <iostream>

void InformationGame::setTime(const int& currentTime) {
	m_currentTime = currentTime;
}

int InformationGame::getTime() const {
	std::cout << m_currentTime;
	return m_currentTime;
}
void InformationGame::setGobletCollected(const unsigned& goblets) {
	m_gobletCollected = goblets;
}

unsigned InformationGame::getGobletCollected() const {
	return m_gobletCollected;
}