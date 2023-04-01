#include "Goblet.h"
Goblet::Goblet()
{
	m_sprite.setTexture(*GameTexture::instance().getTexture(GOBLET));
	m_sprite.setScale(0.3, 0.3);
	m_sprite.setTextureRect(*m_gobletAnimation.get_uvRect());

}

Goblet::~Goblet()
{
}