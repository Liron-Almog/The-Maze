#include "FactoryObj.h"
#include "Factory.h"
#include "Wall.h"
#include "Door.h"
#include "Player.h"
#include "Coin.h"
#include "Empty.h"
#include "Enemy.h"
FactoryObj::FactoryObj() {


Factory<StaticObject>::registerit('w',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Wall>(); });

Factory<StaticObject>::registerit('d',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Door>(); });

Factory<StaticObject>::registerit('g',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Coin>(); });

Factory<StaticObject>::registerit(' ',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Empty>(); });

Factory<MovingObject>::registerit('P',
	[]() -> unique_ptr<MovingObject> { return std::make_unique <Player> (); });

Factory<MovingObject>::registerit('E',
	[]() -> unique_ptr<MovingObject> { return std::make_unique <Enemy>(); });

}