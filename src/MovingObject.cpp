#include "MovingObject.h"

sf::Vector2f MovingObject::getDirection() const {
	return m_direction;
}
void MovingObject::setDirection(const sf::Vector2f  dir) {
	m_direction = dir;
}
float MovingObject::getSpeed() {
	return m_speed;
}