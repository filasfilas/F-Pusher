#include "SFML/Graphics.hpp"
#include "headers/Box.h"
#include "headers/ResourceIdentifiers.h"


Box::Box (TileType type, sf::Sprite spriteSheet, sf::Vector2i intPos)
:Tile(type, spriteSheet, intPos)
{
	mTarget=false;
	isMoving=false;

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

void Box::move (sf::Vector2i newPosition, TileType newTile)
{
	if (isMoving == true) {return;} //prevent new mov command while previous moving is not finished
	isMoving = true;
	mTimer = 0.0;
	newIntPos = newPosition;
	newTileType = newTile;

	speed = sf::Vector2f((newIntPos.x-getIntPosition().x)*HERO_SPEED*1.0, (newIntPos.y-getIntPosition().y)*HERO_SPEED*1.0);

	mIntPosition = newPosition;
}

void Box::update(float dt)
{
	if(isMoving == false) 
	{
		setIntPosition(newIntPos);
		return;
	}

	mTimer += dt;
	if(mTimer > ANIMATION_TIME)
	{
		isMoving=false;
		mTimer=0.0;

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
		setIntPosition(newIntPos);
	}
	mSprite.setPosition(mSprite.getPosition()+speed*dt);
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
