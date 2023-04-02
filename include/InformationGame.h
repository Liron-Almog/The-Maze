#pragma once
class InformationGame
{
public:

	InformationGame() =default;
	~InformationGame() = default;

	void setGobletCollected(const unsigned&);
	void setTime(const int& currentTime);

	int getTime() const;
	unsigned getGobletCollected() const;

private:
	unsigned m_gobletCollected;
	int m_currentTime;
};

