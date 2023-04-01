#pragma once
class InformationGame
{
public:

	InformationGame() =default;
	~InformationGame() = default;

	void setTime(const int& currentTime);
	int getTime() const;
	void setGobletCollected(const int& currentTime);
	int getGobletCollected() const;

private:
	unsigned m_gobletCollected;
	int m_currentTime;
};

