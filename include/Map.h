#pragma once
#include <SFML/Graphics.hpp>
#include "GameTexture.h"
#include <iostream>     
#include <fstream>
#include <vector>
#include "StaticObject.h"
#include "Factory.h"
#include "InformationGame.h"
#include "MovingObject.h"
#include "CollisionHandling.h"
#include "Graph.h"
#include "Player.h"
#include <iostream>
#include "Const.h"
#include "GameTime.h"
#include "InformationBar.h"
#include "Door.h"
#include "Wall.h"
#include "Empty.h"
class Map
{
public:

	//===========Getter functions=================
	int getTime() const;
	void getPositionOfSourceAndTarget(int& source, int& target);

	//===========Setter functions=================
	void setPlayerDirection(const sf::Vector2f &);

	//=============Constructor================
	Map();

	//=============Destructor================
	~Map() = default;


	void createObject(char charachter, sf::Vector2f location, const int& row);
	unsigned getCoinCollected() const;
	void checkWheterMakeDFS();
	bool isTimeOver();
	bool isGameOver() const;
	void checkDisposedObject();
	void paintTheTrackViaDFS();
	void addEdgesForGraph();
	void clearVectors();
	void checksCollistion();
	bool isColiistion(const GameObject& ob1, const GameObject& ob2);
	void UpdateStatusGame();
	void drawMap(sf::RenderWindow& window);
	void moveObj(const float& deltaTime);	
	void checkNeighborsAndInsert(const int& row, const int& col);
	void readMapFromFile(const bool);

private:

	Player *getPointerToPlayer() const;

	void paintTheTrack(const vector<int>& track);
	void openFileMap();

	InformationGame m_informationGame;
	InformationBar m_informationBar = InformationBar(&m_informationGame);

	CollisionHandling m_collisionHandling;
	Graph m_graph = Graph(WIDTH_OF_MAP * HEIGHT_OF_MAP);
	vector<unique_ptr<MovingObject>> m_movingObj;
	vector<vector<unique_ptr<StaticObject>>> m_staticObj;
	std::fstream m_file;
	sf::Sprite m_background;
	GameTime m_gameTime;
	bool m_gameOver = false,
			m_DFS = false;

};

