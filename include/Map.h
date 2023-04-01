#pragma once
#include <SFML/Graphics.hpp>
#include "GameTexture.h"
#include <iostream>     
#include <fstream>
#include <vector>
#include "StaticObject.h"
#include "Factory.h"
#include "ControllerObj.h"
#include "CollisionHandling.h"
#include "Graph.h"
#include "Const.h"
#include "GameTime.h"
#include "InformationBar.h"
#include "Door.h"
#include "Wall.h"
#include "Empty.h"
class Map
{
public:

	void checkWheterMakeDFS();
	bool isTimeOver();
	bool isGameOver() const;
	void setNextLevel();
	void checkDisposedObject();
	void paintTheTrackViaDFS();
	void addEdgesForGraph();
	unsigned getLevel() const;
	void clearVectors();
	void checksCollistion();
	bool isColiistion(const GameObject& ob1, const GameObject& ob2);
	void insertPlayer(const char&, const sf::Vector2f&, vector<unique_ptr<StaticObject>>&);
	Map();
	~Map() = default;
	void drawMap(sf::RenderWindow& window);
	void movePlayer(const sf::Vector2f& direction, const float& deltaTime);	
	void checkNeighborsAndInsert(const int& row, const int& col);
	void getPositionOfSourceAndTarget(int & source, int & target);

private:

	void paintTheTrack(const vector<int>& track);
	void readMapFromFile(const bool);
	void openFileMap();

	InformationBar m_informationBar;
	CollisionHandling m_collisionHandling;
	Graph m_graph = Graph(WIDTH_OF_MAP * HEIGHT_OF_MAP);
	unique_ptr<ControllerObj> m_player ;
	vector<vector<unique_ptr<StaticObject>>> m_staticObj;
	unsigned m_level = 1;
	std::fstream m_fileMaps;
	sf::Sprite m_background;
	GameTime m_gameTime;
	bool m_gameOver = false,
			m_DFS = false;

};

