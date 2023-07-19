#pragma once
#include "Command.h"
#include "GameTexture.h"
#include "Controller.h"
#include "Const.h"
#include "SingeltonSound.h"
#include "Animation.h"
class Start : public Command
{

public:
	
	//=========Constructor============
	Start();

	//=========Virtual functions==============
	virtual ~Start() = default;
	bool execute(sf::RenderWindow& window) override;

private:
	
	sf::Sprite m_loadingSprite;
};

