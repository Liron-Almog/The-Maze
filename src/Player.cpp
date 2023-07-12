#include "StriteMove.h"
#include "Player.h"
Player::Player()
{

	m_moveBehavior = make_unique< StriteMove>();
	m_speed = PLAYER_SPEED;
	m_sprite.setTexture(*GameTexture::instance().getTexture(PLAYER));
	m_sprite.setScale(0.9, 0.9);
	m_sprite.setTextureRect(*m_playerAnimation.get_uvRect());
	m_backgroundPlayer.setTexture(*GameTexture::instance().getTexture(SQUARE_INSIDE_SQUARE));
	m_backgroundPlayer.setOrigin(m_backgroundPlayer.getTexture()->getSize().x/2,
							    m_backgroundPlayer.getTexture()->getSize().y / 2);
}
void Player::incGoblet() {

	m_goblet++;

}
//--------getGobelt-------
unsigned Player::getGobelt() const {
	return m_goblet;
}

void Player::moveStepBack() {
	m_sprite.move(-m_direction.x*m_speed, -m_direction.y * m_speed);
}
Player::~Player()
{
}

void Player::move(const float& elapsedTime) {

	if (m_direction.x != 0 || m_direction.y != 0) {
	
		m_playerAnimation.updateAnimation(m_playerAnimation.getRowByDirection(m_direction), elapsedTime);//calculates the right animation
		m_sprite.setTextureRect(*m_playerAnimation.get_uvRect());
		m_direction = sf::Vector2f(m_direction.x * elapsedTime, m_direction.y * elapsedTime);
		m_moveBehavior->moveObject(*this);

	}
}

void Player::draw(sf::RenderWindow& window) {
	
	m_backgroundPlayer.setPosition(m_sprite.getPosition().x + 50, m_sprite.getPosition().y+30);
	window.draw(m_sprite);
	window.draw(m_backgroundPlayer);
}
