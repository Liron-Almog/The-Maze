#pragma once
#include "Const.h"
class Animation
{
public:
	//===========Constructor=============
	Animation(sf::Vector2i, float, const sf::Texture&);
	Animation() {};
	//=========Destractor================
	~Animation() = default;

	void updateAnimation(const int&, float);
	const sf::IntRect* get_uvRect() const;

	//=================getter method==================
	int getRowByDirection(const sf::Vector2f&) const;

private:

	sf::Vector2i m_rowAndColOfImage;
	double m_maximumTime = 0;
	sf::Vector2i  m_currentImage = sf::Vector2i(0, 0);
	double	m_changeBetweenTextureTime;
	sf::IntRect m_uvRect;

};
