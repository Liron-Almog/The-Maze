#include "Map.h"
#include "Player.h"
//------------UpdateStatusGame--------------
void Map::UpdateStatusGame() {

	m_informationGame.setGobletCollected(this->getGlobletCollected());
	m_informationGame.setTime(m_gameTime.getTime());
}
//------------movePlayer--------------------
void Map::moveObj(const float& elapsedTime) {

	m_player->move(elapsedTime);
}
//-------------setPlayerDirection------------------
void Map::setPlayerDirection(const sf::Vector2f& dir) {
	
	m_player->setDirection(dir);
	/*for (int i = 0; i < m_movingObject.size(); i++)
	{
		if (Ghost* ghost = dynamic_cast<Ghost*>(m_movingObject[i].get()))
			ghost->setPrevDirection(m_player->getSprite().getPosition());*/
}
//-------------checksCollistion-------------
void Map::checksCollistion() {

	for (size_t i = 0; i < m_staticObj.size(); i++)
		for (size_t j = 0; j < m_staticObj[i].size(); j++)
			if (isColiistion(*m_player, *m_staticObj[i][j]))
					m_collisionHandling.processCollision(*m_player, *m_staticObj[i][j]);

	checkDisposedObject();
	checkWheterMakeDFS();
	
}
//--------------getTime--------------------
int Map::getTime() const {
	return m_gameTime.getTime();
}
//--------------getTime--------------------
unsigned Map::getGlobletCollected() const {

	Player* player;
	player = static_cast<Player*>(m_player.get());
	return player->getGobelt();
}
//------------checkWheterMakeDFS-----------
void Map::checkWheterMakeDFS() {

	Player* player;
	player = static_cast<Player*>(m_player.get());

	if (player->getGobelt() == MAXIMUM_GOBLET && !m_DFS)
		paintTheTrackViaDFS();
}
//------------checkDisposedObject-----------
void Map::checkDisposedObject() {

	for (size_t i = 0; i < m_staticObj.size(); i++)
		for (size_t j = 0; j < m_staticObj[i].size(); j++)
			if (m_staticObj[i][j]->isDisposed()) {

				if (m_staticObj[i][j]->getSprite().getTexture() ==
					GameTexture::instance().getTexture(DOOR))
					readMapFromFile(true);

				
				auto pos = m_staticObj[i][j]->getSprite().getPosition();
				m_staticObj[i][j].release();
				m_staticObj[i][j] = Factory<StaticObject>::create(' ');
				m_staticObj[i][j]->setTilePosition(pos);
			}
}
//-----------------getLevel-----------------
unsigned Map::getLevel() const {
	return m_level;
}
//---------------clearVectors----------------
void Map::clearVectors() {

	m_staticObj.clear();
	m_player.reset();
}
//-----------------setNextLevel-----------------
void Map::setNextLevel() {

	m_level++;
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

	Player* player;
	player = static_cast<Player*>(m_player.get());
	
	window.draw(m_background);
	for (size_t i = 0; i < m_staticObj.size(); i++) 
		for (size_t j = 0; j < m_staticObj[i].size(); j++)
				m_staticObj[i][j]->draw(window);
			
	m_player->draw(window);
	m_informationBar.draw(window);

}
//---------------constructor------------------
Map::Map()
{
	m_background.setTexture(*GameTexture::instance().getBackgroundGame());
	openFileMap();
	readMapFromFile(true);
	UpdateStatusGame();
}

//--------------readMapFromFile----------
void Map::readMapFromFile(const bool nextLevel) {

	char tile;

	if (!nextLevel)
		m_fileMaps.seekg(-((HEIGHT_OF_MAP) * (WIDTH_OF_MAP + 2) + 3), std::ios::cur);

	else {
		m_fileMaps >> m_level;
		m_DFS = false;
	}

	if (m_level == GAME_OVER) {
		m_gameOver = true;
		return;
	}
	clearVectors();
	m_gameTime.startTime();
	for (size_t row = 0; row < HEIGHT_OF_MAP; row++) {
		tile = m_fileMaps.get();//eats the \n
		vector<unique_ptr<StaticObject>> temp;
		for (size_t col = 0; col < WIDTH_OF_MAP; col++){

			tile = m_fileMaps.get();
			insertPlayer(tile, sf::Vector2f(col * (WALL_SIZE) +10 + WALL_SIZE*2, row * (WALL_SIZE +1) + 160), temp);
		}
		m_staticObj.push_back(move(temp));
	}
	tile = m_fileMaps.get();//eats the \n
	addEdgesForGraph();
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

	for (int row = 0; row < m_staticObj.size() ; row++)
		for (int col = 0; col < m_staticObj[row].size(); col++) {

			if (isColiistion(*m_player, *m_staticObj[row][col]) && typeid(* m_staticObj[row][col]) != typeid(Wall))
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
	if (row + 1 < HEIGHT_OF_MAP && typeid(*m_staticObj[row+1][col]) != typeid(Wall))
		m_graph.addEdge(currentNode, (row + 1) * WIDTH_OF_MAP + col);

	// left node
	if (col - 1 > -1 && typeid(*m_staticObj[row][col-1]) != typeid(Wall))
		m_graph.addEdge(currentNode, row * WIDTH_OF_MAP + col -1);
	// right node
	if (col + 1 < WIDTH_OF_MAP && typeid(*m_staticObj[row][col+1]) != typeid(Wall))
		m_graph.addEdge(currentNode, row * WIDTH_OF_MAP + col + 1);
}
//The function gets tile that presents tool on mapand inserts
//to the appropriate  vector by "factory design patterns"
//-----------insertPlayer------------------
void Map::insertPlayer(const char& tile, const sf::Vector2f& pos, vector<unique_ptr<StaticObject>>& temp) {



	if (isupper(tile)) {//ControllerObj players
		m_player = (Factory<MovingObject>::create(tile));
		m_player->setTilePosition(pos);
		temp.emplace_back(Factory<StaticObject>::create(' '));
		temp[temp.size() - 1]->setTilePosition(pos);
	}

	if (islower(tile)|| tile == ' ') {//static players
		temp.emplace_back(Factory<StaticObject>::create(tile));
		temp[temp.size() - 1]->setTilePosition(pos);
	}
}
//-----------openFileMap----------------------
void Map::openFileMap() {

	m_fileMaps.open("Board.txt");//open file
	if (!m_fileMaps.is_open())
		throw std::runtime_error("Cannot open a file");

}