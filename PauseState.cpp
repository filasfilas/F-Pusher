#include "headers/PauseState.h"
#include "headers/Utility.h"

PauseState::PauseState(GlobalDataRef gData) 
: gData(gData)
{
}

void PauseState::init()
{
    //background.setTexture(gData -> mAssets.getTexture(Textures::TitleScreen));

	titleText.setString(L"PAUSED");
	titleText.setFont(gData-> mAssets.getFont(Fonts::Main));
	centerOrigin(titleText);
	titleText.setPosition(sf::Vector2f(gData-> mWindow.getSize() / 2u));

	//gData -> mMusic.play(Music::MenuTheme);
}

void PauseState::handleInput(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		gData -> mStates.removeState();
	}

}

void PauseState::update (float dt)
{}

void PauseState::draw(float dt )
{
//    gData -> mWindow.draw(background);
	gData -> mWindow.draw(titleText);
}

void PauseState::stop()
{
	gData -> mMusic.stop();
}

void PauseState::pause()
{
	gData -> mMusic.setPaused(true);
}

void PauseState::resume()
{
	gData -> mMusic.setPaused(false);
}
