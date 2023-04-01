#include "InformationGame.h"
void InformationGame::setTime(const int& currentTime) {
	m_currentTime = currentTime;
}

int InformationGame::getTime() const {
	return m_currentTime;
}
void InformationGame::setGobletCollected(const int& currentTime) {
	m_gobletCollected = m_gobletCollected;
}

int InformationGame::getGobletCollected() const {
	return m_gobletCollected;
}