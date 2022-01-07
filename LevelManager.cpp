#include "headers/LevelManager.h"
#include <string>
#include <fstream>
#include <iostream>

LevelManager::LevelManager(GlobalDataRef gData)
:gData(gData)
,mHero(gData)
{
}

void LevelManager::loadLevel(int level)
{
	currLevel = level;
	//std::cout<<"Level: "<<currLevel<<std::endl;

	//load level from file, creating string vector "stringMap"
	std::vector<std::string> stringMap;
	std::string filename = "levels/"+std::to_string(level) +".txt";
	std::ifstream file (filename);
	std::string str;

	//read file
	while (file)
	{
		getline(file, str);
		stringMap.push_back(str);
	}
	file.close();

	stringMap.erase(stringMap.begin()); //delete first string with special data
	stringMap.pop_back(); //delete empty last string (EOF ?)
	rows = stringMap.size()-1;
	str = stringMap.back();
	columns = str.size();

	//creating level (floor, boxes, hero), based on stringMap
	sf::Sprite spriteSheet;
	spriteSheet.setTexture(gData -> mAssets.getTexture(Textures::Tiles));
	
	sf::Vector2i	intPosition;
	TileType		type;
	mMap.clear();
	mBoxes.clear();
	saveBoxMove.clear();

	std::vector<TilePtr> temp;
	for (int j=0; j<rows; j++) // read rows by rows
	{
		str = stringMap[j];
		//std::cout<<str<<std::endl;
		for (int i=0; i<columns; i++) // colums
		{
			temp.clear();
			type = EMPTY;
			intPosition = sf::Vector2i(i, j);
			//reading tile type
			if (str.substr(i,1) == "@") //hero
			{
				mHero.init(sf::Vector2i(i,j));
			}
			if (str.substr(i,1) == "+") //hero and target
			{
				mHero.init(sf::Vector2i(i,j));
				type = TARGET;
			}
			if (str.substr(i,1) == "$") //box
			{	
				mBoxes.push_back(std::move(BoxPtr(new Box(BOX, spriteSheet, intPosition))));
			}
			if (str.substr(i,1) == "?") //box and target
			{	
				mBoxes.push_back(std::move(BoxPtr(new Box(BOX, spriteSheet, intPosition))));
				type = TARGET;
			}
			if (str.substr(i,1) == "#") //wall
			{	
				type = WALL;
			}
			if (str.substr(i,1) == ".") //target place
			{	
				type = TARGET;
			}	
			
			mMap.push_back(std::move(TilePtr(new Tile(type, spriteSheet, intPosition))));
		}
	}
	chekBoxesOnTarget(); //check if box is on a target place
}

void LevelManager::draw()
{
	for (int i=0; i<mMap.size(); i++)
	{
		mMap[i] -> draw(gData -> mWindow);

	}
	for (int i=0; i<mBoxes.size(); i++)
	{
		mBoxes[i] -> draw(gData -> mWindow);
	}
	mHero.draw(gData -> mWindow);
}

sf::Vector2i LevelManager::getNextCellPosition(sf::Vector2i position, Direction direction)
{
	if (direction == UP)
	{	position.y -= 1;}
	if (direction == DOWN)
	{	position.y += 1;}
	if (direction == LEFT)
	{	position.x -= 1;}
	if (direction == RIGHT)
	{	position.x += 1;}

	return position;	
}


int LevelManager::vecNum(sf::Vector2i position) //returns number in vector mMap, based on screen position
{
	int result =  (position.y)*columns + (position.x);
	return result;
}


TileType LevelManager::getCellType(sf::Vector2i position)
{
	return (mMap[vecNum(position)] -> getType ());
}


bool LevelManager::isCompleted()
{
	bool result = true;
	for (int i=0; i<mBoxes.size(); i++)
	{
		if( !(mBoxes[i] -> isOnTarget()))
		{	result = false;}
	}
	return result;
}

void LevelManager::move(Direction direction)
{
	sf::Vector2i newPos = getNextCellPosition(mHero.getIntPosition(), direction);
	sf::Vector2i newPos2 = getNextCellPosition(newPos, direction);

	mHero.turn(direction);
	//check if there is a box at next position
	if (getBoxNumber(newPos)>-1)
	{
		if (getBoxNumber(newPos2)>-1) //another box behind - no move
		{	return;}
		if (getCellType(newPos2) == WALL) //wall behind box - no move
		{	return;}

		saveBoxMove.push_back(getBoxNumber(newPos));	
		mBoxes[getBoxNumber(newPos)] -> savePosition();	
		mBoxes[getBoxNumber(newPos)] -> move(newPos2, getCellType(newPos2));
		mHero.savePosition();
		mHero.move(newPos, direction);
		return;
	}

	//check if can move (no box ahead)
	if ((getCellType(newPos) == EMPTY) or (getCellType(newPos) == TARGET))
	{
		mHero.move(newPos, direction);
		return;
	}	
}

int LevelManager::getBoxNumber(sf::Vector2i pos)
{
	int result =-1;
	for (int i=0; i<mBoxes.size(); i++)
	{
		if((mBoxes[i] -> getIntPosition()) == pos)
		{
			result = i;
		}
	}
	return result;
}

void LevelManager::undo()
{
	mHero.undoPosition();
	if(!saveBoxMove.empty())
	{
		//std::cout<<saveBoxMove.back()<<std::endl;	
		mBoxes[saveBoxMove.back()] -> undoPosition();
		saveBoxMove.pop_back();
		chekBoxesOnTarget();
	}
}

void LevelManager::chekBoxesOnTarget()
{
	for (int i=0; i<mBoxes.size(); i++)
	{
		sf::Vector2i pos;
		pos = (mBoxes[i] -> getIntPosition());
		mBoxes[i] -> move(pos, getCellType(pos));
	}
}

void LevelManager::update(float dt)
{
	mHero.update(dt);
	for (int i=0; i<mBoxes.size(); i++)
	{
		mBoxes[i] -> update(dt);
	}
}
