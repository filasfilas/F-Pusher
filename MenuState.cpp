#include "headers/MenuState.h"
#include "headers/GameState.h"
#include "headers/LevelSelectionState.h"
#include "headers/Utility.h"
#include "headers/Definitions.h"


MenuState::MenuState(GlobalDataRef gData) 
: gData(gData)
{
}

void MenuState::init()
{
	texture = gData -> mAssets.getTexture(Textures::TitleScreen);
	texture.setRepeated(true);
	background.setTexture(texture);
	background.setTextureRect(sf::IntRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT));

	titleText.setString(L"МENU");
	titleText.setFont(gData-> mAssets.getFont(Fonts::Main));
	centerOrigin(titleText);
	titleText.setPosition(sf::Vector2f(SCREEN_WIDTH/2,40));


	//prepare buttons
	sf::Sprite sprite;
	sf::Text text;

	sprite.setTexture(gData -> mAssets.getTexture(Textures::PlayButton));
	//sprite.setScale(0.3, 0.3);	
	centerOrigin(sprite);
	text.setFont(gData-> mAssets.getFont(Fonts::Main));
	centerOrigin(text);

	//play button
	text.setString(L"Start New");
	sprite.setPosition(sf::Vector2f(SCREEN_WIDTH/2,200));
	playBtn.setButton(sprite, text);

	//start level button
	text.setString(L"Choose Level");
	sprite.setPosition(sf::Vector2f(SCREEN_WIDTH/2,350));
	choseLevelBtn.setButton(sprite, text);	

	//exit button
	text.setString(L"Exit");
	sprite.setPosition(sf::Vector2f(SCREEN_WIDTH/2,500));
	exitBtn.setButton(sprite, text);


	//gData -> mMusic.play(Music::MenuTheme);
}

void MenuState::handleInput(const sf::Event& event)
{
	if (exitBtn.isClicked(sf::Mouse::Left, gData -> mWindow))
	{
		gData -> mStates.removeState();
	}
	if (choseLevelBtn.isClicked(sf::Mouse::Left, gData -> mWindow))
	{
		gData -> mStates.addState(StatePtr (new LevelSelectionState(gData)));
	}
	if (playBtn.isClicked(sf::Mouse::Left, gData -> mWindow))
	{
		gData -> mStates.replaceState(StatePtr (new GameState(gData, 1)));
	}
}

void MenuState::update (float dt)
{}

void MenuState::draw(float dt )
{
    gData -> mWindow.draw(background);
	gData -> mWindow.draw(titleText);

	playBtn.draw(gData -> mWindow);
	choseLevelBtn.draw(gData -> mWindow);
	exitBtn.draw(gData -> mWindow);
}

void MenuState::stop()
{
	//gData -> mMusic.stop();
}

void MenuState::pause()
{
	//gData -> mMusic.setPaused(true);
}

void MenuState::resume()
{
	//gData -> mMusic.setPaused(false);
}
