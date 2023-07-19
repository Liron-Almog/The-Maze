#include "Wall.h"

//=========Constructor============
Wall::Wall()
{
	m_sprite.setTexture(*GameTexture::instance().getTexture(WALL));	
}