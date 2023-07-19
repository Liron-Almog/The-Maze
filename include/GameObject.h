#pragma once
#include "Const.h"
#include "GameTexture.h"
class GameObject 
{
public:

	//==============Constructor============
	GameObject() = default;

	//=================Virtual methods==================
	virtual ~GameObject() = default;
    virtual void draw(sf::RenderWindow& window);

	//================Getter method==============
	const sf::Sprite& getSprite() const;

	//===============Setter methods===============
	void setSpriteScale(const double& x, const double& y);
	void setDisposed() ;
	void setTilePosition(const sf::Vector2f pos);
	void setColor(const sf::Color color);
	void setTexture(const playersAndAnimation_t& type);

	bool isDisposed() const;
	void moveSprite(const sf::Vector2f&);

protected:

	bool m_isDisposed = false;
	sf::Sprite m_sprite;
	
private:


};

