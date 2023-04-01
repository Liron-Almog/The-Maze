#include "GameObject.h"

GameObject::GameObject()
{

}
//---------------draw----------------
void GameObject::draw(sf::RenderWindow& window) {

	window.draw(m_sprite);
}
//-----------setPlayerPosition------------
void GameObject::setTilePosition(const sf::Vector2f pos) {
	m_sprite.setPosition(pos.x, pos.y);
}
//---------------isDisposed--------------
bool GameObject::isDisposed() const
{
	return m_isDisposed;
}
void GameObject::setColor(const sf::Color color){

	m_sprite.setColor(color);
}
//---------------isDisposed--------------
void GameObject::setDisposed()
{
	m_isDisposed = true;
}
//------------getSprite------------
const sf::Sprite& GameObject::getSprite() const {
	return m_sprite;
}
