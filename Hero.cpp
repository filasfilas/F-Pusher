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
	isMoving = false;
}

void Hero::init(sf::Vector2i pos)
{
	setIntPosition (pos);
	posSaves.clear();
	mDirection = DOWN;
	isMoving = false;
	animTime = 0.0;
	mTimer = 0.0;
}

void Hero::draw(sf::RenderWindow& window) 
{
//	gData -> mWindow.draw(mSprite);
	window.draw(mSprite);
}

void Hero::move(sf::Vector2i newPos, Direction direction)
{
	if (isMoving == true) {return;} //prevent new mov command while previous moving is not finished
	isMoving = true;
	animTime = 0.0;
	mTimer = 0.0;
	newIntPos = newPos;
	//setIntPosition(newPos);
	mDirection = direction;
	speed = sf::Vector2f((newIntPos.x-getIntPosition().x)*HERO_SPEED*1.0, (newIntPos.y-getIntPosition().y)*HERO_SPEED*1.0);
	mIntPosition = newPos;
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

	if(isMoving == false)
	{
		mFrame =0;
		mAnimation[mDirection][mFrame].setPosition(mSprite.getPosition());
	}
	else
	{
		animate(dt);
		mTimer += dt;
		if (mTimer > ANIMATION_TIME)	
		{	
			isMoving = false;
			mTimer = 0.0;
			setIntPosition(newIntPos);
		}
		mAnimation[mDirection][mFrame].setPosition(mSprite.getPosition()+speed*dt);
	}
	mSprite = mAnimation[mDirection][mFrame];
}

void Hero::animate(float dt)
{
	animTime += dt;
	if(animTime>ANIMATION_TIME_STEP)
	{
		animTime = 0.0;
		mFrame++;
		if (mFrame>2){mFrame=0;}
	}
}

