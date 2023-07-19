#pragma once
#include "Const.h"
#include <SFML/Audio.hpp>
class SingeltonSound
{
public:

	~SingeltonSound() = default;
	static SingeltonSound& instance();
	void playMusic(const int&);
	void pauseMusic(const int&);

private:

	void loadGameMusic();
	SingeltonSound();
	SingeltonSound(const SingeltonSound&) = default;
	SingeltonSound& operator=(const SingeltonSound&) = default;
	sf::Music m_musicGame[MUSIC];

};

