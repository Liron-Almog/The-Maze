#include "Enemy.h"
#include <iostream>

//============Constructor=============
Enemy::Enemy() 
{
    m_sprite.setScale(1.3, 1.3);
    m_sprite.setTexture(*GameTexture::instance().getTexture(ENEMY));
    m_sprite.setTextureRect(*m_enemyAnimation.get_uvRect());
    m_moveBehavior = std::make_unique<RandomMove>();
}

//The function lotterys a new direction
//============changeDirection==========
void Enemy::changeDirection()
{

    RandomMove* myMoveBehavior;
    myMoveBehavior = dynamic_cast<RandomMove*>(m_moveBehavior.get());
    setDirection(myMoveBehavior->changeDirection(m_direction));
}

//===========move==============
void Enemy::move(const float& timepassed)
{

    m_enemyAnimation.updateAnimation(m_enemyAnimation.getRowByDirection(m_direction), timepassed);//calculates the right animation
    m_sprite.setTextureRect(*m_enemyAnimation.get_uvRect());//sets the correct texture
    m_speed = timepassed * SPEED_ENEMY;
    m_moveBehavior->moveObject(*this);
  
}
void Enemy::moveBack()
//==========moveBack=============
{
	m_sprite.move(-sf::Vector2(m_direction.x* m_speed, m_direction.y * m_speed));
}
