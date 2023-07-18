#pragma once
#include "Const.h"
class Animation
{
public:

	//===========Constructor=============
	Animation(sf::Vector2i, float, const sf::Texture&);

	//=========Destractor================
	~Animation() = default;

	//=================Getter methods==================
	int getRowByDirection(const sf::Vector2f&) const;
	const sf::IntRect* get_uvRect() const;

	void updateAnimation(const int&, float);

private:

	sf::Vector2i m_rowAndColOfImage,
				 m_currentImage = sf::Vector2i(0, 0);
	double m_maximumTime = 0, 
		   m_changeBetweenTextureTime;
	sf::IntRect m_uvRect;

};
