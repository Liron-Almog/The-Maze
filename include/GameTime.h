#pragma once
#include "Const.h"
class GameTime
{
public:

	//==============Constructor============
	GameTime() = default;

	//==============Destructor============
	~GameTime() = default;

	//=======Getter functions==============
	int getTime() const;

	void startTime();

private:

	int m_totalTime;
	sf::Clock m_gameTime;
};

