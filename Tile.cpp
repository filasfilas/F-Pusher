#include "SFML/Graphics.hpp"
#include "headers/Tile.h"
#include "headers/ResourceIdentifiers.h"


Tile::Tile (TileType type, sf::Sprite spriteSheet, sf::Vector2i intPos)
{
	mType = type;
	mSprite = spriteSheet;

	mSprite.setTextureRect(sf::IntRect(11*SOURCE_SPRITE_SIZE, 6*SOURCE_SPRITE_SIZE, SOURCE_SPRITE_SIZE, SOURCE_SPRITE_SIZE)); //default sprite (transparent)
	if (mType == WALL)
	{mSprite.setTextureRect(sf::IntRect(7*SOURCE_SPRITE_SIZE, 6*SOURCE_SPRITE_SIZE, SOURCE_SPRITE_SIZE, SOURCE_SPRITE_SIZE));}
	if (mType == TARGET)
	{mSprite.setTextureRect(sf::IntRect(12*SOURCE_SPRITE_SIZE, SOURCE_SPRITE_SIZE, SOURCE_SPRITE_SIZE, SOURCE_SPRITE_SIZE));}
	if (mType == BOX)
	{mSprite.setTextureRect(sf::IntRect(SOURCE_SPRITE_SIZE, 0, SOURCE_SPRITE_SIZE, 2*SOURCE_SPRITE_SIZE));}

	mSprite.scale(SPRITE_SCALE, SPRITE_SCALE);
	setIntPosition(intPos);
}


void Tile::draw(sf::RenderWindow& window) 
{
	window.draw(mSprite);
}

void Tile::setIntPosition(sf::Vector2i intPos)
{
	mIntPosition = intPos;
	mSprite.setPosition(sf::Vector2f(intPos.x*TILE_SIZE, intPos.y*TILE_SIZE));
}

