#include "CollisionHandling.h"
#include "GameObject.h"
#include "Wall.h"
#include "Player.h"
#include "Door.h"
#include "Enemy.h"
#include "Coin.h"
#include "Lightning.h"
//===================doorPlayer===================
void doorPlayer(GameObject& gameObject1, GameObject& gameObject2)
{

    Door& door = static_cast<Door&>(gameObject2);
    Player& player = static_cast<Player&>(gameObject1);

    if(player.getCoins() == MAXIMUM_COINS)
        door.setDisposed();
    else player.moveStepBack();

}
//===================playerGoblet===================
void playerCoin(GameObject& gameObject1, GameObject& gameObject2)
{

    Coin& coin = static_cast<Coin&>(gameObject2);
    Player& player = static_cast<Player&>(gameObject1);

  
    if (coin.getSprite().getTexture() == GameTexture::instance().getTexture(COIN)) {
        player.incCoin();
        coin.setTexture(EMPTY);
        coin.resetViewRect(COIN);
        coin.setSpriteScale(1, 1);
    }
    
 
}
//===================wallPlayer===================
void wallPlayer(GameObject& gameObject1, GameObject& gameObject2) 
{

    Player& player = static_cast<Player&>(gameObject1);
    player.moveStepBack();
    
}
//===================enemyWall===================
void enemyWall(GameObject& gameObject1, GameObject& gameObject2)
{

    Enemy& enemy = static_cast<Enemy&>(gameObject1);
    enemy.moveStepBack();
    enemy.changeDirection();

}
//===================enemyPlayer===================
void enemyPlayer(GameObject& gameObject1, GameObject& gameObject2)
{

    Player& player = static_cast<Player&>(gameObject2);
    player.setDisposed();
 

}
//===================playerLightning===================
void playerLightning(GameObject& gameObject1, GameObject& gameObject2)
{

    Player& player = static_cast<Player&>(gameObject1);
    Lightning& lightning = static_cast<Lightning&>(gameObject2);


    if (lightning.getSprite().getTexture() == GameTexture::instance().getTexture(LIGHTNING)) {
        player.setExtraSpeed(0.3);
        lightning.setTexture(EMPTY);
    }

}
//===================processCollision===================
void CollisionHandling::processCollision(GameObject& object1, GameObject& object2) {

    auto phf = lookUp(typeid(object1), typeid(object2));
        if (phf)
             phf(object1, object2);

}
//===================Constructor===================
CollisionHandling::CollisionHandling()
{
    m_collisionMap[Key(typeid(Enemy), typeid(Player))] = &enemyPlayer;
    m_collisionMap[Key(typeid(Enemy), typeid(Wall))] = &enemyWall;
    m_collisionMap[Key(typeid(Enemy), typeid(Door))] = &enemyWall;
    m_collisionMap[Key(typeid(Player), typeid(Wall))] = &wallPlayer;
    m_collisionMap[Key(typeid(Player), typeid(Door))] = &doorPlayer;
    m_collisionMap[Key(typeid(Player), typeid(Coin))] = &playerCoin;
    m_collisionMap[Key(typeid(Player), typeid(Lightning))] = &playerLightning;
   

}

// Look up the collision handling function based on two class types.
// Returns a pointer to the collision handling function.
// If no matching entry is found in the collision map, nullptr is returned.
HitFunctionPtr CollisionHandling::lookUp(const std::type_index& class1, const std::type_index& class2)
{
    // Find an entry in the collision map that matches the pair of class types.
    auto mapEntry = m_collisionMap.find(std::make_pair(class1, class2));

    // If no matching entry is found, return nullptr.
    if (mapEntry == m_collisionMap.end())
        return nullptr;

    // Return the collision handling function pointer from the found map entry.
    return mapEntry->second;
}
