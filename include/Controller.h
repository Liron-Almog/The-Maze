
#include "Map.h"
#include "GameFont.h"

class Controller
{
public:

	//==============Constructor============
	Controller();

	//==============Destractor============
	~Controller() = default;

	//==============Getter functions============
	sf::Vector2f getDirection();

	void handleEvents(sf::RenderWindow& window);
	void drawGame(sf::RenderWindow&);
	void drawAndSleep(sf::RenderWindow& window, const sf::Sprite& sprite);
	void run(sf::RenderWindow& window);
	void checkStatusGame(sf::RenderWindow& window);

private:

	sf::Sprite m_spriteTimeIsOver, m_spriteGameIsOver;
	Map m_map;
	sf::Text m_title;
	bool m_inGame = false;

};

