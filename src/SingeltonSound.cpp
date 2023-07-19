#include "SingeltonSound.h"

//===============Singelton=============
SingeltonSound& SingeltonSound::instance() 
{
	static SingeltonSound instance;
	return instance;

}

//===============constructor============
SingeltonSound::SingeltonSound() 
{

	loadGameMusic();
}

//===========playMusic=============
void SingeltonSound::playMusic(const int& number) 
{

	if (number < MUSIC)
	{
		m_musicGame[number].play();
		m_musicGame[number].setLoop(true);
	}

}
//===========pauseMusic=============
void SingeltonSound::pauseMusic(const int& number) 
{
	if (number < MUSIC) 
		m_musicGame[number].pause();
}

//=============loadGameMusic=======
void SingeltonSound::loadGameMusic() 
{
	m_musicGame[GAME_MUSIC].openFromFile("game.wav");
	m_musicGame[MENU_MUSIC].openFromFile("menu.wav");
	m_musicGame[MENU_MUSIC].setVolume(28.f);
	m_musicGame[GAME_MUSIC].setVolume(18.f);
}