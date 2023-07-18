#include "Empty.h"

//========Constructor========
Empty::Empty()
{
	m_sprite.setTexture(*GameTexture::instance().getTexture(EMPTY));
}
