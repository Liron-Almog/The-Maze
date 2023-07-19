#include "RandomMove.h"
#include "MovingObject.h"
#include <iostream>

//=========moveObject==========
void RandomMove::moveObject(MovingObject& obj) {

   
    auto dir = sf::Vector2(obj.getSpeed() * obj.getDirection().x, obj.getSpeed() * obj.getDirection().y);
    m_number++;

    if (m_number == m_changeDir) { //If the enemy needs to change direction
        obj.setDirection(sf::Vector2f(changeDirection(obj.getDirection())));
        m_changeDir = rand() % 1000 + 500;
        m_number == 0;
        return;
    }
    obj.moveSprite(dir);
}
//The function lotterys a new direction
//============changeDirection==========
sf::Vector2f RandomMove::changeDirection(sf::Vector2f m_prevDirection)
{

    if (m_prevDirection.x != 0)
        m_prevDirection.x = 1;
    else  m_prevDirection.y = 1;
   
    sf::Vector2f newDirection = m_prevDirection;
    while (newDirection == m_prevDirection) {
        int num = rand() % DIRECTIONS;

        if (num == 0)
            newDirection = LEFT;

        if (num == 1)
            newDirection = DOWN;

        if (num == 2)
            newDirection = RIGHT;

        if (num == 3)
            newDirection = UP;
    }
   return newDirection;
}
