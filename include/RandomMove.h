#pragma once
#include "MoveBehavior.h"

class RandomMove :public MoveBehavior
{
public:
	RandomMove() =default;
	sf::Vector2f changeDirection(sf::Vector2f m_prevDirection);
	~RandomMove() = default;
	void moveObject(MovingObject& obj);
private:
	int m_changeDir = 1000;
	int m_number = 0;
};


