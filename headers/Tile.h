#pragma once

#include "SFML/Graphics.hpp"
#include "Definitions.h"

enum TileType
{
	EMPTY,
	WALL,
	BOX,
	EXIT,
	TARGET,
};


class Tile
{
	public:
		Tile (TileType type, sf::Sprite spriteSheet, sf::Vector2i intPos);

		void draw(sf::RenderWindow& window);
		void setPosition(sf::Vector2f pos);

		TileType getType () {return mType;};
		sf::Vector2i getIntPosition () {return mIntPosition;};
		void setIntPosition(sf::Vector2i intPos);

	protected:
		TileType		mType;
		sf::Sprite		mSprite;
		sf::Vector2i	mIntPosition;

};
