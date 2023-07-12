#include "Enemy.h"
#include <iostream>

Enemy::Enemy() 
//============Constructor=============
{
  
   // m_enemyAnim = Animation(sf::Vector2i(4, 4), 0.16, *SingeltonTexture::instance().getTexture(CHARACTER, ENEMY_TEXTURE));//initialize the animation
    //m_sprite.setTexture(*SingeltonTexture::instance().getTexture(CHARACTER, ENEMY_TEXTURE));
    m_sprite.setTextureRect(*m_enemyAnim.get_uvRect());
    m_moveBehavior = std::make_unique<RandomMove>();
 
   // changeDirection();
}

void Enemy::changeDirection()
//============changeDirection==========
//The function lotterys a new direction
{

    RandomMove* myMoveBehavior;
    myMoveBehavior = dynamic_cast<RandomMove*>(m_moveBehavior.get());
    setDirection(myMoveBehavior->changeDirection(m_direction));


}

void Enemy::move(const float& timepassed)
//===========move==============
{

    int correctRowForAnimation = m_enemyAnim.getRowByDirection(m_direction);

    m_enemyAnim.updateAnimation(correctRowForAnimation, timepassed);//calculates the right animation
    m_sprite.setTextureRect(*m_enemyAnim.get_uvRect());//sets the correct texture

    //creates direction + speed + time that was passed
    m_speed = timepassed * SPEED_ENEMY;

    m_moveBehavior->moveObject(*this);
  
}
void Enemy::moveBack()
//==========moveBack=============
{
	m_sprite.move(-sf::Vector2(m_direction.x* m_speed, m_direction.y * m_speed));
}
