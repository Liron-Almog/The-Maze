#include "Start.h"

//The virtual function executes the start button 
//-----------execute-------------
bool Start::execute(sf::RenderWindow& window) {

	drawTransitionAndAnimation(window);

	Controller game;
	game.run(window);
	
	//returns background to starting point
	return true;
}
//-----------constructor-------------
Start::Start() {

	m_transitionScreen.setTexture(*GameTexture::instance().getTransitionScreen(MENU_BACKGROUND));
	//initializes the login animation
	m_loadingSprite.setTexture(*GameTexture::instance().getTexture(LOADING));
	m_loadingSprite.scale(3.5, 3.5);
	m_loadingSprite.setPosition(510,380);
}
//The function draws The animation and transition screen.
//-------------drawTransitionAndAnimation------------------------
void Start::drawTransitionAndAnimation(sf::RenderWindow& window) {

	
	float elapsedTime = 0.0f,sum = 0.0f;
	sf::Clock clock;
	int lastImage = -1;
	
	while (sum < TIME_OF_LOGIN_ANI)
	{
		elapsedTime = clock.restart().asSeconds();
		m_loadingAnimation.update(0, elapsedTime);
		sum += elapsedTime;

		if (lastImage != m_loadingAnimation.getCurrentImage().x) {//if the photo changed from last time  
			lastImage = m_loadingAnimation.getCurrentImage().x;
			m_loadingSprite.setTextureRect(*m_loadingAnimation.get_uvRect());
			drawTransitionScreen(window);
			window.draw(m_loadingSprite);
			window.display();
		}
	}

}
