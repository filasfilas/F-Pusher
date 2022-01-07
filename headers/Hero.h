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
		bool 			isMoving;
		float			animTime;
		float			mTimer;
		Direction		mDirection;
		sf::Vector2i	newIntPos;
		sf::Vector2i	mIntPosition;
		sf::Vector2f	speed;

		std::vector <sf::Vector2i>	posSaves;

		void setIntPosition(sf::Vector2i pos);
		void animate(float dt);

};
