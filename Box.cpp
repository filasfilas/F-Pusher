#include "SFML/Graphics.hpp"
#include "headers/Box.h"
#include "headers/ResourceIdentifiers.h"


Box::Box (TileType type, sf::Sprite spriteSheet, sf::Vector2i intPos)
:Tile(type, spriteSheet, intPos)
{
	mTarget=false;

	arrSprite[0] =mSprite;
	arrSprite[1] =mSprite;
	arrSprite[0].setTextureRect(sf::IntRect(SOURCE_SPRITE_SIZE, 0, SOURCE_SPRITE_SIZE, SOURCE_SPRITE_SIZE));
	arrSprite[1].setTextureRect(sf::IntRect(SOURCE_SPRITE_SIZE, SOURCE_SPRITE_SIZE, SOURCE_SPRITE_SIZE, SOURCE_SPRITE_SIZE));
	mSprite=arrSprite[0];
}


bool Box::isOnTarget()
{
	return mTarget;
}


sf::Vector2i Box::getIntPosition()
{
	return mIntPosition;
}

void Box::move (sf::Vector2i newPosition, TileType newTileType)
{
	if (newTileType == TARGET)
	{	
		mTarget = true;
		mSprite=arrSprite[1];
	}
	else
	{	
		mTarget = false;
		mSprite=arrSprite[0];
	}
	setIntPosition(newPosition);
}

void Box::savePosition()
{
	posSaves.push_back(mIntPosition);
}

void Box::undoPosition()
{
	if (!posSaves.empty())
	{
		setIntPosition (posSaves.back());
		posSaves.pop_back();
	}
}
