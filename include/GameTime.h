#pragma once
#include "Const.h"
class GameTime
{
public:

	GameTime() = default;
	~GameTime() = default;
	int getTime() const;
	void startTime();
	void updateTime();


private:

	int m_totalTime;
	sf::Clock m_gameTime;
};

