#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <map>
#include <iterator>
#include <cstdlib>
#include <typeinfo>
#include <stdexcept>
#include <typeindex>

class GameObject;
using namespace std;

using HitFunctionPtr = void (*)(GameObject&, GameObject&);
using Key = pair<type_index, type_index>;
using HitMap = map<Key,void (*)(GameObject&, GameObject&)>;

const int FPS = 60
	, WALL_SIZE = 44
	, HEIGHT_OF_MAP = 13
	, WIDTH_OF_MAP = 25
	, SPEED_ENEMY = 70
	, PLAYER_SPEED = 125
	, FIRST_LEVEL = 1
	, SCREEN_H = 800
	, NUM_OF_PHOTHS_IN_COIN_ANIMATION = 8
	, SCREEN_W = 1600
	, GAME_TIME = 100
	, TIME_OF_LOGIN_ANI = 4
	, MAXIMUM_COINS = 4
	, DIRECTIONS = 4
	,GAME_OVER = 0
		, NO_OPTION = -1;



const float SHOW_TIME = 2;
const double MAXIMUM_DELTA_TIME = 1.0;
const char GAME_OVER_SING = '0';

const sf::Vector2f
		LEFT = sf::Vector2f((float)-1, 0)
		, RIGHT = sf::Vector2f((float)1, 0)
		, STAND = sf::Vector2f(0, 0)
		, UP = sf::Vector2f(0, (float)(-1))
		, DOWN = sf::Vector2f(0, (float)(1));

enum font_t{
	TITLE_FONT,
	CANDY_FONT,
	SHARPSHOTER_FONT,
	TIME_FONT,
	NUMBER_OF_FONT
};

enum backGroumd_t {
	GAME_BACKGROUND,
	MENU_BACKGROUND,
	INFO_BACKGROUND,
	NUMBER_OF_BACKGROUND
};
enum music_t {
	GAME_MUSIC,
	MENU_MUSIC,
	MUSIC
};


enum transitionScreens_t {
	START_SCREEN,
	TIME_IS_OUT_SCREEN,
	NEXT_LEVEL_SCREEN,
	GAME_OVER_SCREEN,
	QUIT_SCREEN,
	NUMBER_OF_TRANSITION_SCREENS
};
enum playersAndAnimation_t {
	PLAYER,
	WALL,
	DOOR,
	EMPTY,
	ENEMY,
	LIGHTNING,
	SQUARE_INSIDE_SQUARE,
	COIN,
	CLOCK,
	NUMBER_OF_OBJECT
};

enum informationBar_t {
	TEXT ,
	DATA,
	TEXT_AND_DATA
};
