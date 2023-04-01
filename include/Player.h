#include "Animation.h"
#include "Const.h"
#include "GameTexture.h"
#include "ControllerObj.h"

class Player : public ControllerObj
{
public:

	Player();
	~Player();
	unsigned getGobelt() const;
	void moveStepBack();
	void move(const sf::Vector2f& direction, const float& deltaTime);
	void updateAnimation(const float&){}//ignore
    virtual void draw(sf::RenderWindow& window) override;
	void incGoblet();

private:

	unsigned m_goblet = 0;
	sf::Vector2f m_lastDireation = DOWN;
	Animation m_playerAnimation = Animation(*GameTexture::instance().getTexture(PLAYER)
		, sf::Vector2u(4, 4), 0.25);
	sf::Sprite m_backgroundPlayer;

};