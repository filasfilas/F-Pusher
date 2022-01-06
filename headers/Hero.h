#pragma once

#include "SFML/Graphics.hpp"
#include "Application.h"
#include "Definitions.h"

#include <vector>


class Hero
{
	public:
		Hero (GlobalDataRef   gData);
	
		void init(sf::Vector2i pos);
		void draw(sf::RenderWindow& window);
		void move(sf::Vector2i newPos, Direction direction);
		
		sf::Vector2i getIntPosition () {return mIntPosition;};
		void savePosition();
		void undoPosition();
		void update(float dt);
		void turn (Direction direction) {mDirection = direction;};


	private:
        GlobalDataRef   gData;

		sf::Sprite		mSprite;
		sf::Sprite		mAnimation[5][3];
		int				mFrame;
		Direction		mDirection;
		sf::Vector2i	mIntPosition;

		std::vector <sf::Vector2i>	posSaves;

		void setIntPosition(sf::Vector2i pos);

};
