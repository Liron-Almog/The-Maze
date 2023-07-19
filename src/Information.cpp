#include "Information.h"
#include "Command.h"
#include "Menu.h"
#include "GameTexture.h"
#include "Back.h"
#include "Const.h"

//The virtual function executes the information button
//=============execute============
 bool Information::execute(sf::RenderWindow& window) {

	 Menu informationMenu(*GameTexture::instance().getBackground(INFO_BACKGROUND),"", sf::Color(197, 179, 88));
	 informationMenu.add("Back", std::make_unique<Back>(),sf::Vector2i(50, 720));//creates back button
	 informationMenu.draw(window);
	 informationMenu.activate(window);

	 return true;
}

 