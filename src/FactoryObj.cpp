#include "FactoryObj.h"
#include "Factory.h"
#include "Wall.h"
#include "Door.h"
#include "Player.h"
#include "Goblet.h"
#include "Empty.h"

FactoryObj::FactoryObj() {


Factory<StaticObject>::registerit('w',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Wall>(); });

Factory<StaticObject>::registerit('d',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Door>(); });

Factory<StaticObject>::registerit('g',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Goblet>(); });

Factory<StaticObject>::registerit(' ',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Empty>(); });

Factory<MovingObject>::registerit('P',
	[]() -> unique_ptr<MovingObject> { return std::make_unique <Player> (); });


}