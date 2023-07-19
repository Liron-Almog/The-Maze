#include "Animation.h"
#include "Const.h"
#include "GameTexture.h"
#include "MovingObject.h"

class Player : public MovingObject
{
public:

	//==========Constructor===========
	Player();
	//=========Destructor============
	~Player() = default;

	//==========Virtual functions=============
	virtual void draw(sf::RenderWindow& window) override;

	//==========Getter functions===========	
	unsigned getCoins() const;

	//==========Setter function=====
	void setSpeed(const float&);
	void move(const float& deltaTime);
	void incCoin();

private:

	unsigned m_coin = 0;
	Animation m_playerAnimation = Animation(sf::Vector2i(4, 4) , 0.25 ,*GameTexture::instance().getTexture(PLAYER));
	sf::Sprite m_backgroundPlayer;

};