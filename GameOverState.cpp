#include "headers/GameOverState.h"
#include "headers/Utility.h"
#include "headers/MenuState.h"

GameOverState::GameOverState(GlobalDataRef gData, std::string gameOverType) 
: gData(gData)
{
	overText.setString(gameOverType);
}

void GameOverState::init()
{
//    background.setTexture(gData -> mAssets.getTexture(Textures::TitleScreen));

	//titleText.setString(L"Нажмите любую клавишу");
	overText.setFont(gData-> mAssets.getFont(Fonts::Main));
	centerOrigin(overText);
	overText.setPosition(sf::Vector2f(gData-> mWindow.getSize() / 2u));
}

void GameOverState::handleInput(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		gData -> mStates.replaceAllStates(StatePtr(new MenuState(gData)));
	}
}

void GameOverState::update (float dt)
{}

void GameOverState::draw(float dt )
{
//    gData -> mWindow.draw(background);
	gData -> mWindow.draw(overText);
}
