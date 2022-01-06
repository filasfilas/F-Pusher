#include "headers/LevelSelectionState.h"
#include "headers/GameState.h"
#include "headers/Utility.h"
#include "headers/Definitions.h"


LevelSelectionState::LevelSelectionState(GlobalDataRef gData) 
: gData(gData)
{
}

void LevelSelectionState::init()
{
	strLevel="";
	level=0;

	texture = gData -> mAssets.getTexture(Textures::SmallMenu);
	texture.setRepeated(true);
	background.setTexture(texture);
	background.setTextureRect(sf::IntRect(0,0, 8*TILE_SIZE,3*TILE_SIZE));
	centerOrigin(background);
	background.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

	titleText.setString(L"Enter Level 1-105");
	titleText.setFont(gData-> mAssets.getFont(Fonts::Main));
	titleText.setCharacterSize(16);
	centerOrigin(titleText);
	titleText.setPosition(sf::Vector2f(SCREEN_WIDTH/2,370));

	levelText.setFont(gData-> mAssets.getFont(Fonts::Main));
	levelText.setCharacterSize(16);

	//gData -> mMusic.play(Music::MenuTheme);
}

void LevelSelectionState::handleInput(const sf::Event& event)
{

	if (event.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed (sf::Keyboard::Escape))
		{
			gData -> mStates.removeState();
		}
		if (sf::Keyboard::isKeyPressed (sf::Keyboard::Enter))//enter new level
		{
			if(level <1)
			{	level=1;}
			if(level >MAX_LEVEL)
			{	level =MAX_LEVEL;}

			gData -> mStates.replaceAllStates(StatePtr (new GameState(gData, level)));
		}

		if (event.key.code == sf::Keyboard::Num0)	{int num=0; level=level*10+num;}
		if (event.key.code == sf::Keyboard::Num1)	{int num=1; level=level*10+num;}
		if (event.key.code == sf::Keyboard::Num2)	{int num=2; level=level*10+num;}
		if (event.key.code == sf::Keyboard::Num3)	{int num=3; level=level*10+num;}
		if (event.key.code == sf::Keyboard::Num4)	{int num=4; level=level*10+num;}
		if (event.key.code == sf::Keyboard::Num5)	{int num=5; level=level*10+num;}
		if (event.key.code == sf::Keyboard::Num6)	{int num=6; level=level*10+num;}
		if (event.key.code == sf::Keyboard::Num7)	{int num=7; level=level*10+num;}
		if (event.key.code == sf::Keyboard::Num8)	{int num=8; level=level*10+num;}
		if (event.key.code == sf::Keyboard::Num9)	{int num=9; level=level*10+num;}

		if (level>999) {level=level%1000;}
	}
}

void LevelSelectionState::update (float dt)
{
	strLevel = std::to_string(level);
	levelText.setString(strLevel);
	centerOrigin(levelText);
	levelText.setPosition(sf::Vector2f(SCREEN_WIDTH/2,400));
}

void LevelSelectionState::draw(float dt )
{
    gData -> mWindow.draw(background);
	gData -> mWindow.draw(titleText);
	gData -> mWindow.draw(levelText);
	
}

void LevelSelectionState::stop()
{
	//gData -> mMusic.stop();
}

void LevelSelectionState::pause()
{
	//gData -> mMusic.setPaused(true);
}

void LevelSelectionState::resume()
{
	//gData -> mMusic.setPaused(false);
}
