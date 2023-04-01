
#include "Player.h"
Player::Player()
{
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
	m_sprite.move(-m_lastDireation);
}
Player::~Player()
{
}

void Player::move(const sf::Vector2f& direction, const float& elapsedTime) {

	m_lastDireation = sf::Vector2f(direction.x * PLAYER_SPEED * elapsedTime, direction.y * PLAYER_SPEED * elapsedTime);
	m_sprite.move(m_lastDireation);
	m_playerAnimation.update(m_playerAnimation.getRowOfStandatAni(direction), elapsedTime);
	m_sprite.setTextureRect(*m_playerAnimation.get_uvRect());
}

void Player::draw(sf::RenderWindow& window) {
	
	m_backgroundPlayer.setPosition(m_sprite.getPosition().x + 50, m_sprite.getPosition().y+30);
	window.draw(m_sprite);
	window.draw(m_backgroundPlayer);
}
