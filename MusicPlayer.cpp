#include "headers/MusicPlayer.h"


MusicPlayer::MusicPlayer()
: mMusic()
, mVolume(100.f)
{
	mFilenames[Music::MainTheme]    = "media/music/Komiku_-_02_-_Poupis_Theme.ogg";
}

void MusicPlayer::play(Music::ID music)
{
	std::string filename = mFilenames [music];
	if (!mMusic.openFromFile(filename))
		throw std::runtime_error("Music " + filename + " could not be loaded.");	

	mMusic.setVolume(mVolume);
	mMusic.setLoop(true);
	mMusic.play();
}

void MusicPlayer::stop()
{
	mMusic.stop();
}

void MusicPlayer::setPaused(bool paused)
{
	if(paused)
	{
		mMusic.pause();
	}
	else
	{
		mMusic.play();
	}
}

void MusicPlayer::switchPaused()
{
	if(mMusic.getStatus() == sf::Music::Paused)
	{
		mMusic.play();
	}
	else
	{
		mMusic.pause();
	}
}


void MusicPlayer::setVolume(float volume)
{
	mVolume = volume;
	mMusic.setVolume(mVolume);
}
