#include "Door.h"
#include "GameTexture.h"

//========Constructor========
Door::Door()
{
	m_sprite.setTexture(*GameTexture::instance().getTexture(DOOR));
}
