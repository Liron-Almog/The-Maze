#pragma once
class InformationGame
{
public:

	//========Constructor==========
	InformationGame() = default;

	//========Destructor==========
	~InformationGame() = default;

	//=========Setter function============
	void setCoinCollected(const unsigned&);
	void setTime(const int& currentTime);

	//========Getter functions==========
	int getTime() const;
	unsigned getGobletCollected() const;

private:

	unsigned m_gobletCollected;
	int m_currentTime;
};

