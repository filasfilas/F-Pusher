#include "SFML/Graphics.hpp"
#include "headers/Hero.h"
#include "headers/ResourceIdentifiers.h"

Hero::Hero(GlobalDataRef   gData)
:gData(gData)
,mDirection(RIGHT)
{
	mDirection = DOWN;
	mFrame=0;
		
	int xStart=0, yStart=4;


	for (int i =0; i<5; i++)
	{
		if (i==RIGHT) {xStart=0; yStart=6;}
		if (i==LEFT) {xStart=3; yStart=6;}
		if (i==DOWN) {xStart=0; yStart=4;}
		if (i==UP) {xStart=3; yStart=4;}

		for (int j =0; j<3; j++)
		{
			mAnimation[i][j].setTexture(gData -> mAssets.getTexture(Textures::Tiles));
			mAnimation[i][j].setTextureRect(sf::IntRect((xStart+j)*SOURCE_SPRITE_SIZE,  yStart*SOURCE_SPRITE_SIZE, SOURCE_SPRITE_SIZE, SOURCE_SPRITE_SIZE)); 
			mAnimation[i][j].scale(SPRITE_SCALE, SPRITE_SCALE);
		}
	}

	mSprite = mAnimation[mDirection][0];
	setIntPosition(sf::Vector2i(0,0));
}

void Hero::init(sf::Vector2i pos)
{
	setIntPosition (pos);
	posSaves.clear();
}

void Hero::draw(sf::RenderWindow& window) 
{
//	gData -> mWindow.draw(mSprite);
	window.draw(mSprite);
}

void Hero::move(sf::Vector2i newPos, Direction direction)
{
	setIntPosition(newPos);
	mDirection = direction;
}

void Hero::setIntPosition(sf::Vector2i pos)
{
	mIntPosition = pos;
	mSprite.setPosition(sf::Vector2f(pos.x*TILE_SIZE, pos.y*TILE_SIZE));
}

void Hero::savePosition()
{
	posSaves.push_back(mIntPosition);
}

void Hero::undoPosition()
{
	if (!posSaves.empty())
	{
		setIntPosition (posSaves.back());
		posSaves.pop_back();
	}
}

void Hero::update(float dt)
{
	if((mDirection<1) or (mDirection>4)) {mDirection=DOWN;}
	sf::Vector2f pos = mSprite.getPosition();
	mAnimation[mDirection][mFrame].setPosition(pos);
	mSprite = mAnimation[mDirection][mFrame];
}
