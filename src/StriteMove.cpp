#include "StriteMove.h"
#include "MovingObject.h"

//========moveObject=======
void StriteMove::moveObject(MovingObject& obj) {

	obj.moveSprite(sf::Vector2f(obj.getDirection().x * obj.getSpeed(), obj.getDirection().y * obj.getSpeed()));

}