#include "headers/MusicPlayer.h"


MusicPlayer::MusicPlayer()
: mMusic()
, mVolume(100.f)
{
	mFilenames[Music::MenuTheme]    = "media/music/MenuTheme.ogg";
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

void MusicPlayer::setVolume(float volume)
{
	mVolume = volume;
	mMusic.setVolume(mVolume);
}
