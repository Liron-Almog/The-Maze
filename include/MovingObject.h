#pragma once
#include "GameObject.h"
#include "MoveBehavior.h"

class MovingObject :public GameObject
{
public:

	 MovingObject() = default;
	float getSpeed();
	sf::Vector2f getDirection() const;
	void setDirection(const sf::Vector2f);
	virtual ~MovingObject () = default;
	virtual void updateAnimation(const float& s){};
	void virtual move(const float& time) {
		m_direction = sf::Vector2f(time * m_direction.x, time * m_direction.y);
		m_moveBehavior->moveObject(*this);
	}


protected:

	std::unique_ptr<MoveBehavior> m_moveBehavior;
	float m_speed = 0;
	sf::Vector2f m_direction = sf::Vector2f(0, 1);

private:



};

