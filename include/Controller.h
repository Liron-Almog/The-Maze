
#include "Map.h"
#include "GameFont.h"
class Controller
{
public:

	Controller();
	~Controller();
	sf::Vector2f getDirection();
	void handleEvents(sf::RenderWindow& window);
	void drawGame(sf::RenderWindow&);
	void run(sf::RenderWindow& window);
	void checkStatusGame(sf::RenderWindow& window);

private:

	Map m_map;
	sf::Text m_title;
};

