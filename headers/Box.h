#pragma once

#include "Tile.h"
#include <vector>


class Box : public Tile
{
	public:
		Box(TileType type, sf::Sprite spriteSheet, sf::Vector2i intPos);

		bool isOnTarget();
		sf::Vector2i getIntPosition();
		void move (sf::Vector2i newPosition, TileType newTile);
		void update (float dt);

		void savePosition();
		void undoPosition();

	private:
		bool		mTarget;
		bool		isMoving;
		float		mTimer;
		TileType	newTileType;

		sf::Vector2i	newIntPos;
		sf::Vector2f	speed;
		sf::Sprite		arrSprite[2];

		std::vector <sf::Vector2i>	posSaves;

};
