#pragma once
#include "MoveBehavior.h"

class RandomMove :public MoveBehavior
{
public:

	//=========Constructor============
	RandomMove() = default;

	//=========Desstructor============
	~RandomMove() = default;

	sf::Vector2f changeDirection(sf::Vector2f m_prevDirection);
	void moveObject(MovingObject& obj) override;

private:
	int m_changeDir = 1000;//after 1000 times change directions
	int m_number = 0;
};


