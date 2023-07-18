#pragma once
#include "Const.h"
class Command {
	
public:

	//===========Constructor=============
	Command();

	//=========Destractor================
	virtual ~Command() = default;
	
	//==========Virtual methods=============
	virtual bool execute(sf::RenderWindow& window) = 0;

	//============Setter method==========
	void setText(const string&, const sf::Vector2i&);

	void drawTransitionScreen(sf::RenderWindow&);
	void sleep(const int&) const;
	const sf::Text & getText() const;


protected:

	sf::Sprite m_transitionScreen;

private:

	sf::Text m_text;
	
};

