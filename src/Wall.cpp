#include "Wall.h"

Wall::Wall()
{
	m_sprite.setTexture(*GameTexture::instance().getTexture(WALL));	
}