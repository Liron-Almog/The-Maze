#include "Animation.h"
#include <iostream>

int Animation::getRowByDirection(const sf::Vector2f& dir) const
//=============getRowOfStandatAni============
//The function returns the corret row of texture by the direction 
{

	if (dir.x == 1 && dir.y == 0)//right
		return 2;
	if (dir.x == -1 && dir.y == 0)//left
		return 1;
	if (dir.x == 0 && dir.y == 1)//down
		return 0;
	if (dir.x == 0 && dir.y == -1)//up
		return 3;

	return 0;//for warning

}
Animation::Animation(sf::Vector2i rowAndColOfImage, float changeBetweenTextureTime, const sf::Texture& photo)
	: m_rowAndColOfImage(rowAndColOfImage), m_changeBetweenTextureTime(changeBetweenTextureTime)
	//==============Constructor===============
{
	m_uvRect.width = photo.getSize().x / float(rowAndColOfImage.x);
	m_uvRect.height = photo.getSize().y / float(rowAndColOfImage.y);
}
const sf::IntRect* Animation::get_uvRect() const {
	//=========getUvRect===========
	return  &m_uvRect;
}


void Animation::updateAnimation(const int& row, float timeThatWasPassed)
//==========updateAnimation==============
//updates animation
{

	m_maximumTime += timeThatWasPassed;
	m_currentImage.y = row;// updates to correct row
	if (m_maximumTime >= m_changeBetweenTextureTime)
	{
		m_maximumTime = 0;
		m_currentImage.x++;
		m_currentImage.x %= m_rowAndColOfImage.x;
	}

	m_uvRect.left = m_currentImage.x * m_uvRect.width;//calculates the correct rect
	m_uvRect.top = m_currentImage.y * m_uvRect.height;

}

