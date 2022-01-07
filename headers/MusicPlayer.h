#pragma once

#include "ResourceIdentifiers.h"

#include <SFML/System/NonCopyable.hpp>
#include "SFML/Audio/Music.hpp"

#include <map>
#include <string>

class MusicPlayer: private sf::NonCopyable
{

public:
		MusicPlayer();
	
	void play(Music::ID  music);
	void stop();
	void setPaused(bool paused);
	void switchPaused();
	void setVolume(float volume);

private:
	sf::Music	mMusic;
	float		mVolume;

	std::map<Music::ID, std::string>	mFilenames;
};
