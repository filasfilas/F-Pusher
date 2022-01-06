#include "headers/TitleState.h"
#include "headers/Utility.h"
#include "headers/MenuState.h"

TitleState::TitleState(GlobalDataRef gData) : gData(gData)
{
}

void TitleState::init()
{
	texture = gData -> mAssets.getTexture(Textures::TitleScreen);
	texture.setRepeated(true);
	background.setTexture(texture);
	background.setTextureRect(sf::IntRect(0,0,816,768));

	int yPos [] = {SCREEN_HEIGHT/2-10, 450, 600, SCREEN_HEIGHT-20};
	int ChrSize [] = {80, 20, 20,14};

	titleText[0].setString(L"PUSHER");
	titleText[1].setString(L"a game by Filas");
	titleText[2].setString(L"Press any key to start");
	titleText[3].setString(L"https://github.com/filasfilas/F-Pusher");

	for (int i=0; i<4; i++)
	{
		titleText[i].setFont(gData-> mAssets.getFont(Fonts::Main));
		//titleText[i].setColor(sf::Color::White);
		titleText[i].setCharacterSize(ChrSize[i]);
		centerOrigin(titleText[i]);

		titleText[i].setPosition(sf::Vector2f(SCREEN_WIDTH/2,yPos[i]));
	}

}

void TitleState::handleInput(const sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased)
	{
		gData -> mStates.replaceState(StatePtr(new MenuState(gData)));
	}
}

void TitleState::update (float dt)
{}

void TitleState::draw(float dt )
{
    gData -> mWindow.draw(background);

	for (int i=0; i<4; i++)
	{
		gData -> mWindow.draw(titleText[i]);
	}
}
