#include "MovingObject.h"

//========getDirection==========
sf::Vector2f MovingObject::getDirection() const {
	return m_direction;
}

//=======setDirection===========
void MovingObject::setDirection(const sf::Vector2f  dir) {
	m_direction = dir;
}

//========getSpeed==========
float MovingObject::getSpeed() {
	return m_speed;
}

//=========moveStepBack=========
void MovingObject::moveStepBack() {
	m_sprite.move(-m_direction.x * m_speed, -m_direction.y * m_speed);
}
//=================move==========
void MovingObject::move(const float& time) {
	m_direction = sf::Vector2f(time * m_direction.x, time * m_direction.y);
	m_moveBehavior->moveObject(*this);
}