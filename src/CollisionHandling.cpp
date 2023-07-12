#include "CollisionHandling.h"
#include "GameObject.h"
#include "Wall.h"
#include "Player.h"
#include "Door.h"
#include "Coin.h"
//The function handles a collision of Door and Player
//--------------wallPlayer--------------------
void doorPlayer(GameObject& gameObject1, GameObject& gameObject2)
{

    Door& door = static_cast<Door&>(gameObject2);
    Player& player = static_cast<Player&>(gameObject1);

    if(player.getGobelt() == MAXIMUM_GOBLET)
        door.setDisposed();
    else player.moveStepBack();

}
void playerGoblet(GameObject& gameObject1, GameObject& gameObject2)
{

    Coin& goblet = static_cast<Coin&>(gameObject2);
    Player& player = static_cast<Player&>(gameObject1);

    goblet.setDisposed();
    player.incGoblet();
    

}
//The function handles a collision of Wall and Player
//--------------wallPlayer--------------------
void wallPlayer(GameObject& gameObject1, GameObject& gameObject2) 
{

    Player& player = static_cast<Player&>(gameObject1);
    player.moveStepBack();
    
}

//void wallComputerPlayer(GameObject& gameObject1, GameObject& gameObject2)
//{
//
//    Player& player = static_cast<Player&>(gameObject1);
//    player.moveStepBack();
//
//}

//--------------processCollision--------------------
void CollisionHandling::processCollision(GameObject& object1, GameObject& object2) {

    auto phf = lookUp(typeid(object1), typeid(object2));
        if (phf)
             phf(object1, object2);

}
//--------------Constructor--------------------
CollisionHandling::CollisionHandling()
{
    m_collisionMap[Key(typeid(Player), typeid(Wall))] = &wallPlayer;
    m_collisionMap[Key(typeid(Player), typeid(Door))] = &doorPlayer;
    m_collisionMap[Key(typeid(Player), typeid(Coin))] = &playerGoblet;
    /*m_collisionMap[Key(typeid(ComputerPlayer), typeid(Wall))] = &wallComputerPlayer;*/

}

//The function searches for the two objects sent to it 
//within the data structure and if it finds it activates 
//the required function otherwise returns null
//----------------lookUp-------------------------
HitFunctionPtr CollisionHandling::lookUp(const std::type_index& class1, const std::type_index& class2)
{

    auto mapEntry = m_collisionMap.find(std::make_pair(class1, class2));
    if (mapEntry == m_collisionMap.end())
        return nullptr;
   
    return mapEntry->second;
}