#include "Controller.h"


void Controller::run(sf::RenderWindow & window) {

    handleEvents(window);
    
}
//-------------------drawGame---------------------------
void Controller::drawGame(sf::RenderWindow& window) {

    window.clear(sf::Color(250, 235, 215));
    m_map.drawMap(window);
    window.draw(m_title);
    window.display();

}
//-------------------handleEvents-----------------------
void Controller::handleEvents(sf::RenderWindow& window) {


    sf::Clock clock;
    float elapedTime = 0.0f;
    sf::Vector2f direction;
    sf::Event event;
    unsigned level = FIRST_LEVEL;

    while (window.isOpen() && !m_map.isGameOver())//In game
    {
        elapedTime = clock.restart().asSeconds();

        m_map.setPlayerDirection(getDirection());
        m_map.moveObj(elapedTime);
        m_map.checksCollistion();
        checkStatusGame(window, level);
        m_map.UpdateStatusGame();
        drawGame(window);
    
    }
}
void Controller::checkStatusGame(sf::RenderWindow& window,unsigned & level) {

    if (m_map.isGameOver()) {
    }
    else if (m_map.isTimeOver()) {
     
    }
    else if (level != m_map.getLevel()) {
        m_map.setNextLevel();
        drawGame(window);
    }
}
//The function returns the direction that chose by user 
//---------------getDirection----------------------
sf::Vector2f Controller::getDirection(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return LEFT;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return RIGHT;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        return UP;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        return DOWN;

    return STAND;
}

Controller::Controller()
{

    m_title.setFont(GameFont::instance().getFont(SHARPSHOTER_FONT));
    m_title.setString("The Maze");
    m_title.setCharacterSize(90);
    m_title.setStyle(sf::Text::Bold);
    m_title.setColor(sf::Color::White);
    m_title.setPosition(sf::Vector2f(370,35));

}

Controller::~Controller()
{
}

