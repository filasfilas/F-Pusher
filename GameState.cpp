#include "headers/GameState.h"
#include "headers/MenuState.h"
#include "headers/GameOverState.h"
#include "headers/PauseState.h"
#include "headers/Utility.h"


GameState::GameState(GlobalDataRef gData, int level=1) 
:gData(gData)
,currLevel(level)
,mLevel(gData)
,mHUD(gData)
{
}

void GameState::init()
{
	texture = gData -> mAssets.getTexture(Textures::TitleScreen);
	texture.setRepeated(true);
	background.setTexture(texture);
	background.setTextureRect(sf::IntRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT));

	mLevel.loadLevel(currLevel);
	mHUD.update(currLevel);

	gData -> mMusic.play(Music::MainTheme); 
}

void GameState::handleInput(const sf::Event& event)
{

	if (event.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed (sf::Keyboard::Escape))
			{gData -> mStates.replaceState(StatePtr (new MenuState(gData)));}

		if (sf::Keyboard::isKeyPressed (sf::Keyboard::Pause))
			{gData -> mStates.addState(StatePtr (new PauseState(gData)));}

		if (sf::Keyboard::isKeyPressed (sf::Keyboard::Backspace))//one step back
			{mLevel.undo();}
		if (event.key.code == sf::Keyboard::R)//restart level
			{mLevel.loadLevel(currLevel);}
	
		
		moveDirection=NO_DIRECTION;
		if (event.key.code == sf::Keyboard::Up)
			{moveDirection=UP;}
		if (event.key.code == sf::Keyboard::Down)
			{moveDirection=DOWN;}
		if (event.key.code == sf::Keyboard::Left)
			{moveDirection=LEFT;}
		if (event.key.code == sf::Keyboard::Right)
			{moveDirection=RIGHT;}
	}
	mHUD.handleInput(event);

}

void GameState::update (float dt)
{

	if (moveDirection != NO_DIRECTION)
	{
		mLevel.move(moveDirection);	
		moveDirection = NO_DIRECTION;
	}
	mLevel.update(dt);

	if (mLevel.isCompleted())
	{
		currLevel++;	
		if (currLevel>105)
		{	gData -> mStates.addState(StatePtr(new GameOverState(gData, "You Win !!!")));}
		else
		{
			mLevel.loadLevel(currLevel);
			mHUD.update(currLevel);
		}
	}

}

void GameState::draw(float dt )
{
    gData -> mWindow.draw(background);
	mLevel.draw();
	mHUD.draw();
}

void GameState::stop()
{
	gData -> mMusic.stop();
}

void GameState::pause()
{
	gData -> mMusic.setPaused(true);
}

void GameState::resume()
{
	gData -> mMusic.setPaused(false);
}
