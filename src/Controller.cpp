#include "Controller.h"

//========================run========================
void Controller::run(sf::RenderWindow & window) {

    handleEvents(window);
    
}
//========================drawGame========================
void Controller::drawGame(sf::RenderWindow& window) {

    window.clear(sf::Color(250, 235, 215));
    m_map.drawMap(window);
    window.draw(m_title);
    window.display();

}
//================handleEvents=================
void Controller::handleEvents(sf::RenderWindow& window) {


    sf::Clock clock;
    float elapedTime = 0.0f;
    sf::Vector2f direction;
    sf::Event event;


    while (window.isOpen() && !m_map.isGameOver())//In game
    {
        elapedTime = clock.restart().asSeconds();//saves the time that passed

        m_map.setPlayerDirection(getDirection());
        m_map.moveObj(elapedTime);
        m_map.checksCollistion();
        checkStatusGame(window);
        if(!m_map.isGameOver())
            m_map.UpdateStatusGame();
            drawGame(window);
    
    }
}
//The function checks the game status 
//==============checkStatusGame=============
void Controller::checkStatusGame(sf::RenderWindow& window) {

    if (m_map.isGameOver() ) {
        drawAndSleep(window, m_spriteGameIsOver);
    }
    else if (m_map.isTimeOver()) {
        drawAndSleep(window, m_spriteTimeIsOver);
        m_map.readMapFromFile(false);
    }
}
//==============drawAndSleep=====================
void Controller::drawAndSleep(sf::RenderWindow& window,const sf::Sprite & sprite) {

    window.clear();
    window.draw(sprite);
    window.display();
    std::this_thread::sleep_for(std::chrono::seconds(3));
}
//The function returns the direction that chose by user 
//==============getDirection=====================
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
//================Constructor==========================
Controller::Controller()
{
    m_title.setFont(GameFont::instance().getFont(SHARPSHOTER_FONT));
    m_title.setString("The Maze");
    m_title.setCharacterSize(90);
    m_title.setStyle(sf::Text::Bold);
    m_title.setColor(sf::Color::White);
    m_title.setPosition(sf::Vector2f(370,35));

    //loading transiction screens
    m_spriteTimeIsOver.setTexture(*GameTexture::instance().getTransitionScreen(TIME_IS_OUT_SCREEN));
    m_spriteGameIsOver.setTexture(*GameTexture::instance().getTransitionScreen(GAME_OVER_SCREEN));
    
}

