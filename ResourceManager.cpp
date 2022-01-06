#include "headers/ResourceManager.h"


void ResourceManager::loadTexture (Textures::ID name, std::string filename)
{
	sf::Texture texture;
	if (texture.loadFromFile(filename))
	{
		mTextures[name]=texture;
	}
}

void ResourceManager::loadFont (Fonts::ID name, std::string filename)
{
	sf::Font font;
	if (font.loadFromFile(filename))
	{
		mFonts[name]=font;
	}
}

void ResourceManager::loadSoundBuffer (Sounds::ID name, std::string filename)
{
	sf::SoundBuffer sound;
	if (sound.loadFromFile(filename))
	{
		mSounds[name]=sound;
	}
}



sf::Texture& ResourceManager::getTexture (Textures::ID name)
{
	return mTextures.at(name);
}

sf::Font& ResourceManager::getFont (Fonts::ID name)
{
	return mFonts.at(name);
}

sf::SoundBuffer& ResourceManager::getSoundBuffer (Sounds::ID name)
{
	return mSounds.at(name);
}
