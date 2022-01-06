#pragma once

#include <vector>

#include "Definitions.h"
#include "Box.h"
#include "Hero.h"

typedef std::unique_ptr<Tile> TilePtr;
typedef std::unique_ptr<Box> BoxPtr;

class LevelManager
{
	public:
		LevelManager(GlobalDataRef   gData);

		void 	loadLevel(int level);
		void 	draw();
		bool	isCompleted();
		void	move(Direction direction);
		bool 	isCanMove(sf::Vector2i heroPosition, Direction moveDirection);
		void	undo();
		void	update(float dt);

	private:
        GlobalDataRef   		gData;

		std::vector<TilePtr>	mMap; 	//FloorMap
		std::vector <BoxPtr>	mBoxes;
		std::vector <int>		saveBoxMove; //save boxes moves by box numbers. Each box saves their positions itself
		Hero					mHero;	

		int	currLevel;	
		int	rows;
		int	columns;

		TileType getCellType(sf::Vector2i position);
		sf::Vector2i getNextCellPosition(sf::Vector2i position, Direction direction);
		int vecNum(sf::Vector2i position); //returns number in vector mMap, based on matrix position 
		int getBoxNumber(sf::Vector2i pos); //returns box number in vector or -1
		void chekBoxesOnTarget(); //check if a box on a target after undo or restart
};
