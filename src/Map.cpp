#include "Map.h"
//------------UpdateStatusGame--------------
void Map::UpdateStatusGame() {

	m_informationGame.setCoinCollected(this->getCoinCollected());
	m_informationGame.setTime(m_gameTime.getTime());
}
//------------movePlayer--------------------
void Map::moveObj(const float& elapsedTime) {

	for (int i = 0; i < m_movingObj.size(); i++)
		m_movingObj[i]->move(elapsedTime);

}
//-------------setPlayerDirection------------------
void Map::setPlayerDirection(const sf::Vector2f& dir) {
	
	Player* player = getPointerToPlayer();
	player->setDirection(dir);

}
//-------------checksCollistion-------------
void Map::checksCollistion() {

	for (size_t i = 0; i < m_staticObj.size(); i++)
		for (size_t j = 0; j < m_staticObj[i].size(); j++) 
			for (size_t k = 0; k < m_movingObj.size(); k++) 
				if (isColiistion(*m_movingObj[k], *m_staticObj[i][j]))
					m_collisionHandling.processCollision(*m_movingObj[k], *m_staticObj[i][j]);

	for (size_t j = 0; j < m_movingObj.size(); j++)
		for (size_t k = 0; k < m_movingObj.size(); k++) 
			if (j != k && isColiistion(*m_movingObj[k], *m_movingObj[j]))
				m_collisionHandling.processCollision(*m_movingObj[k], *m_movingObj[j]);

	checkWheterMakeDFS();
	checkDisposedObject();
	
}
//--------------getTime--------------------
int Map::getTime() const {
	return m_gameTime.getTime();
}
//--------------getTime--------------------
unsigned Map::getCoinCollected() const {

	Player* player = getPointerToPlayer();
	return player->getCoins();
}
Player * Map::getPointerToPlayer() const {

	for (int i = 0; i < m_movingObj.size(); i++) {
		if (Player* player = dynamic_cast<Player*>(m_movingObj[i].get()))
			return player;
	}
}
//------------checkWheterMakeDFS-----------
void Map::checkWheterMakeDFS() {
	
	
	if (getPointerToPlayer()->getCoins() == MAXIMUM_COINS && !m_DFS) {
		addEdgesForGraph();
		paintTheTrackViaDFS();
	}
}
//------------checkDisposedObject-----------
void Map::checkDisposedObject() {

	for (size_t i = 0; i < m_staticObj.size(); i++)
		for (size_t j = 0; j < m_staticObj[i].size(); j++)
			if (m_staticObj[i][j]->isDisposed()) {

				if (m_staticObj[i][j]->getSprite().getTexture() == GameTexture::instance().getTexture(DOOR)) {
					readMapFromFile(true);
					return;
				}

				m_staticObj[i].erase(m_staticObj[i].begin() + j);
			}


	if (getPointerToPlayer()->isDisposed())
		readMapFromFile(false);
}

//---------------clearVectors----------------
void Map::clearVectors() {

	m_staticObj.clear();
	m_movingObj.clear();
}

//-------------------isGameOver-----------------
bool Map::isGameOver() const{

	return m_gameOver;
}
//-------------------isTimeOver-----------------
bool Map::isTimeOver() {
	
	if (m_gameTime.getTime() <= 0) {
		m_gameOver = true;
		return true;
	}
	return false;
}
//------------------------isColiistion-----------------------
bool Map::isColiistion(const GameObject& ob1, const GameObject& ob2) {

	if (ob1.getSprite().getGlobalBounds().intersects(ob2.getSprite().getGlobalBounds()))
		return true;
	return false;
}
//------------------------drawMap----------------------------
void Map::drawMap(sf::RenderWindow& window) {

	window.draw(m_background);
	for (size_t i = 0; i < m_staticObj.size(); i++) 
		for (size_t j = 0; j < m_staticObj[i].size(); j++)
			m_staticObj[i][j]->draw(window);

	for (size_t i = 0; i < m_movingObj.size(); i++)
		m_movingObj[i]->draw(window);

	m_informationBar.draw(window);

}
//---------------constructor------------------
Map::Map()
{
	m_background.setTexture(*GameTexture::instance().getBackground(GAME_BACKGROUND));
	openFileMap();
	readMapFromFile(true);
	UpdateStatusGame();
}

//--------------readMapFromFile----------
void Map::readMapFromFile(const bool nextLevel) {

	m_gameOver = false;
	//clears all the objects
	
	m_movingObj.clear();
	m_staticObj.clear();
	m_staticObj.resize(HEIGHT_OF_MAP);

	if (!nextLevel) 
		m_file.seekg(-((HEIGHT_OF_MAP ) * (WIDTH_OF_MAP + 2)), std::ios::cur);

	//reads map
	for (int row = 0; row < HEIGHT_OF_MAP; row++)
	{
		char charachter;
		if (row != 0)
			charachter = m_file.get();//eats the ENTER

		for (int col = 0; col < WIDTH_OF_MAP; col++)
		{
			charachter = m_file.get();
			if (charachter == GAME_OVER_SING) {
				m_gameOver = true;
				return;
			}

			//calculates the location of object
			auto location = sf::Vector2f(col * (WALL_SIZE)+10 + WALL_SIZE, row * (WALL_SIZE + 1) + 160);
			createObject(charachter, location,row);
		}
	}
	char charachter = m_file.get();
	m_gameTime.startTime();
}
//--------------addEdgesForGraph---------------
void Map::addEdgesForGraph() {

	for (size_t row = 0; row < m_staticObj.size(); row++) {
		for (size_t col = 0; col < m_staticObj[row].size(); col++)
			if (typeid(*m_staticObj[row][col]) != typeid(Wall))
				checkNeighborsAndInsert(row, col);
	}
}

void Map::getPositionOfSourceAndTarget(int & source,int & target) {

	auto player = getPointerToPlayer();

	for (int row = 0; row < m_staticObj.size() ; row++)
		for (int col = 0; col < m_staticObj[row].size(); col++) {

			if (isColiistion(*player, *m_staticObj[row][col]) && typeid(*m_staticObj[row][col]) == typeid(Empty))
				source = row * WIDTH_OF_MAP + col;
			if (typeid(*m_staticObj[row][col]) == typeid(Door))
				target = row * WIDTH_OF_MAP + col;
		}

}
//---------------------------
void Map::paintTheTrackViaDFS(){

	int source, target;
	bool found = false;
	vector<int> track;

	m_DFS = true;
	getPositionOfSourceAndTarget(source,target);
	m_graph.DFS(source, target, found);
	track = m_graph.getTrack();

	paintTheTrack(track);
}
//---------------paintTheTrack----------------
void Map::paintTheTrack(const vector<int> & track) {
	
	
	for (const auto i : track)
		m_staticObj[i / WIDTH_OF_MAP][i % WIDTH_OF_MAP]->setColor(sf::Color::Black);
}
//----------checkNeighborsAndInsert-----------
void Map::checkNeighborsAndInsert(const int & row, const int& col) {

	int currentNode = col + row * WIDTH_OF_MAP;
	//top node
	if (row -1 > -1 && typeid(*m_staticObj[row-1][col]) != typeid(Wall))
		m_graph.addEdge(currentNode, (row - 1) * WIDTH_OF_MAP + col );
	//bottom node
	if (row + 1 < HEIGHT_OF_MAP && m_staticObj[row + 1].size() > col && typeid(*m_staticObj[row+1][col]) != typeid(Wall))
		m_graph.addEdge(currentNode, (row + 1) * WIDTH_OF_MAP + col);

	// left node
	if (col - 1 > -1 && typeid(*m_staticObj[row][col-1]) != typeid(Wall))
		m_graph.addEdge(currentNode, row * WIDTH_OF_MAP + col -1);
	// right node
	if (col + 1 < WIDTH_OF_MAP && m_staticObj[row].size() > col +1 && typeid(*m_staticObj[row][col+1]) != typeid(Wall))
		m_graph.addEdge(currentNode, row * WIDTH_OF_MAP + col + 1);
}
void Map::createObject(char charachter, sf::Vector2f location,const int & row)
//==========createObject==========
//The function creates objects via factory
{
	if (isupper(charachter)) {
		m_movingObj.emplace_back(Factory<MovingObject>::create(charachter));
		m_movingObj[m_movingObj.size() - 1]->setTilePosition(location);
	}
	else if (islower(charachter)) {
		m_staticObj[row].emplace_back(Factory<StaticObject>::create(charachter));
		m_staticObj[row][m_staticObj[row].size()-1]->setTilePosition(location);
	}
	if (charachter == ' ' || isupper(charachter)) {
		m_staticObj[row].emplace_back(Factory<StaticObject>::create(' '));
		m_staticObj[row][m_staticObj[row].size() - 1]->setTilePosition(location);
	}
	
}
//-----------openFileMap----------------------
void Map::openFileMap() {

	m_file.open("Board.txt");//open file
	if (!m_file.is_open())
		throw std::runtime_error("Cannot open a file");

}