#include "Empty.h"
Empty::Empty()
{
	m_sprite.setTexture(*GameTexture::instance().getTexture(EMPTY));
	m_sprite.setScale(-200, -200);
}
