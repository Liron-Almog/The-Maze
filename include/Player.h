#include "Animation.h"
#include "Const.h"
#include "GameTexture.h"
#include "MovingObject.h"

class Player : public MovingObject
{
public:

	Player();
	~Player();
	unsigned getGobelt() const;
	void moveStepBack();
	void move(const float& deltaTime);
	void updateAnimation(const float&){}//ignore
    virtual void draw(sf::RenderWindow& window) override;
	void incGoblet();

private:

	unsigned m_goblet = 0;
	Animation m_playerAnimation = Animation(sf::Vector2i(4, 4) , 0.25 ,*GameTexture::instance().getTexture(PLAYER));
	sf::Sprite m_backgroundPlayer;

};