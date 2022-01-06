#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "ResourceIdentifiers.h"
#include <map>
#include <string>


class ResourceManager
{
	public:
		void            loadTexture (Textures::ID, std::string filename);
		sf::Texture&    getTexture (Textures::ID);

		void            loadFont (Fonts::ID name, std::string filename);
		sf::Font&       getFont (Fonts::ID name);

		void            	loadSoundBuffer (Sounds::ID name, std::string filename);
		sf::SoundBuffer&    getSoundBuffer (Sounds::ID name);

	private:
		std::map<Textures::ID, sf::Texture>  	mTextures;
		std::map<Fonts::ID, sf::Font> 			mFonts;	
		std::map<Sounds::ID, sf::SoundBuffer> 	mSounds;	
};
