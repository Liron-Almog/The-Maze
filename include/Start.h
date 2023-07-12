#pragma once
#include "Command.h"
#include "GameTexture.h"
#include "Controller.h"
#include "Const.h"
#include "Animation.h"
class Start : public Command
{

public:
	
    void drawTransitionAndAnimation(sf::RenderWindow& window);
	bool execute(sf::RenderWindow& window) ;
	Start();
	virtual ~Start() = default;

private:
	
	sf::Sprite m_loadingSprite;
};

