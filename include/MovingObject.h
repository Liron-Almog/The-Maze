#pragma once
#include "GameObject.h"
#include "MoveBehavior.h"

class MovingObject :public GameObject
{
public:

	//=======Constructor==============
	 MovingObject() = default;

	 //=======Destructor==============

	 //=======Getter functions==============
	float getSpeed();
	sf::Vector2f getDirection() const;

	//==========Setter functions
	void setDirection(const sf::Vector2f);

	//========Virtual functions===========
	virtual ~MovingObject () = default;
	void virtual move(const float& time);

	void moveStepBack();

protected:

	std::unique_ptr<MoveBehavior> m_moveBehavior;
	float m_speed = 0;
	sf::Vector2f m_direction = sf::Vector2f(0, 1);

private:



};

