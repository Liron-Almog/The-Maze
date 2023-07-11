#include <exception>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "FactoryObj.h"
#include "Menu.h"
#include "Quit.h"
#include "Information.h"
#include "Start.h"
int main()
{

	try {
		FactoryObj::FactoryObj();//Loads Objs
		sf::RenderWindow window(sf::VideoMode(1200, 800, 32), "The Maze", sf::Style::Close);

		window.setFramerateLimit(FPS);
		sf::Color(197, 179, 88);
		Menu menu(*GameTexture::instance().getBackground(MENU_BACKGROUND),"The Maze", sf::Color(197, 179, 88));
		menu.add("Quit", std::make_unique<Quit>(), sf::Vector2i(530, SCREEN_H + -85 - 170));
		menu.add("Information", std::make_unique<Information>(), sf::Vector2i(442, SCREEN_H + -170 - 170));
		menu.add("Start", std::make_unique<Start>(), sf::Vector2i(515, SCREEN_H + -255 - 170));

		menu.draw(window);
		menu.activate(window);
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
		return EXIT_FAILURE;
	}

	catch (...) {
		std::cerr << "Unknown exception\n";
		return EXIT_FAILURE;
	}
}

