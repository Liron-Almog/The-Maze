#include "Coin.h"

//==============Constructor============
Coin::Coin()
{
	m_sprite.setTexture(*GameTexture::instance().getTexture(COIN));
	m_sprite.setScale(0.7, 0.7);
	m_sprite.setTextureRect(*m_coinAnimation.get_uvRect());

}
//==============draw===================
void Coin::draw(sf::RenderWindow& window)  {

	if (getSprite().getTexture() == GameTexture::instance().getTexture(COIN)){
		m_coinAnimation.updateAnimation(0, 0.06);//calculates the right animation
		m_sprite.setTextureRect(*m_coinAnimation.get_uvRect());
	}

	window.draw(m_sprite);

}
