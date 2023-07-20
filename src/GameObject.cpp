#include "GameObject.h"

//============moveSprite============
void GameObject::moveSprite(const sf::Vector2f& dir) {
	m_sprite.move(dir);
}
//============draw============
void GameObject::draw(sf::RenderWindow& window) {

	window.draw(m_sprite);
}
//============setTilePosition============
void GameObject::setTilePosition(const sf::Vector2f pos) {
	m_sprite.setPosition(pos.x, pos.y);
}

//============isDisposed============
bool GameObject::isDisposed() const
{
	return m_isDisposed;
}

//============setColor============
void GameObject::setColor(const sf::Color color){

	m_sprite.setColor(color);
}

//============setDisposed============
void GameObject::setDisposed()
{
	m_isDisposed = true;
}

//============getSprite============
const sf::Sprite& GameObject::getSprite() const {
	return m_sprite;
}
//============getSprite============
void GameObject::setTexture(const playersAndAnimation_t & type) {
	m_sprite.setTexture(*GameTexture::instance().getTexture(type));
}

void GameObject::setSpriteScale(const double & x, const double& y) {
	m_sprite.setScale(x, y);
}

void GameObject::resetViewRect(const playersAndAnimation_t& type) {
	m_sprite.setTextureRect(sf::IntRect(0, 0, GameTexture::instance().getTexture(type)->getSize().x, GameTexture::instance().getTexture(type)->getSize().y));

}