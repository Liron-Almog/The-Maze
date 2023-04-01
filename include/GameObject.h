#pragma once
#include "Const.h"

class GameObject 
{
public:


	GameObject();
	virtual ~GameObject() = default;
    virtual void draw(sf::RenderWindow& window);
	virtual void updateAnimation(const float &) {};
	void setDisposed() ;
	void setTilePosition(const sf::Vector2f pos);
	bool isDisposed() const;
	void setColor(const sf::Color color);
	const sf::Sprite& getSprite() const;

protected:

	bool m_isDisposed = false;
	sf::Sprite m_sprite;
	
private:


};

