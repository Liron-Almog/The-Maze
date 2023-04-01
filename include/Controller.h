
#include "Map.h"
#include "GameFont.h"
class Controller
{
public:

	sf::Vector2f getDirection();
	Controller();
	~Controller();
	void handleEvents(sf::RenderWindow& window);
	void drawGame(sf::RenderWindow&);
	void run(sf::RenderWindow& window);
	void checkStatusGame(sf::RenderWindow& window, unsigned& level);

private:

	Map m_map;
	sf::Text m_title;
};

