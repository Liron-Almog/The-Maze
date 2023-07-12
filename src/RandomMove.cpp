#include "RandomMove.h"
#include "MovingObject.h"
#include <iostream>


void RandomMove::moveObject(MovingObject& obj) {

   
    auto dir = sf::Vector2(obj.getSpeed() * obj.getDirection().x, obj.getSpeed() * obj.getDirection().y);
    m_number++;
    //If the enemy needs to change direction, gives up on moving
    if (m_number == m_changeDir) {
        obj.setDirection(sf::Vector2f(changeDirection(obj.getDirection())));
        m_changeDir = rand() % 1000 + 500;
        m_number == 0;
        return;
    }
    obj.moveSprite(dir);
}

sf::Vector2f RandomMove::changeDirection(sf::Vector2f m_prevDirection)
//============changeDirection==========
//The function lotterys a new direction
{

    if (m_prevDirection.x != 0)
        m_prevDirection.x = 1;
    else  m_prevDirection.y = 1;
   
    sf::Vector2f newDirection = m_prevDirection;
    while (newDirection == m_prevDirection) {
        int num = rand() % 4;

        if (num == 0)
            newDirection = sf::Vector2f(-1, 0);//left

        if (num == 1)
            newDirection = sf::Vector2f(0, 1);//down

        if (num == 2)
            newDirection = sf::Vector2f(1, 0);//right

        if (num == 3)
            newDirection = sf::Vector2f(0, -1);//up
    }
   return newDirection;
}
