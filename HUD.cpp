#include "headers/HUD.h"
#include "headers/Definitions.h"
#include <string>


HUD::HUD(GlobalDataRef gData)
:gData(gData)
{
	bottomText.setString("ESC-Menu	R-Restart	BACKSPACE-Undo");
	bottomText.setFont(gData-> mAssets.getFont(Fonts::HUD));
	bottomText.setFillColor(sf::Color::Blue);
	bottomText.setCharacterSize(20);
	bottomText.setPosition(15, TILE_SIZE*15+10);

	upperText.setString("LEVEL: " +std::to_string(mLevel));
	upperText.setFont(gData-> mAssets.getFont(Fonts::HUD));
	upperText.setFillColor(sf::Color::Blue);
	upperText.setCharacterSize(24);
	upperText.setPosition(TILE_SIZE*6, 10);

	//prepare button
	sf::Sprite sprite;
	sf::Text text;
	sprite.setTexture(gData -> mAssets.getTexture(Textures::SoundButton));
	//sprite.setScale(0.3, 0.3);	
	text.setString("");
	sprite.setPosition(sf::Vector2f(0,0));
	soundBtn.setButton(sprite, text);
}

void HUD::draw()
{
	gData -> mWindow.draw(upperText);
	gData -> mWindow.draw(bottomText);
	soundBtn.draw (gData -> mWindow);
}

void HUD::update(int currLevel)
{
	mLevel = currLevel;
	upperText.setString("LEVEL: " +std::to_string(mLevel));
}

void HUD::handleInput(const sf::Event& event)
{
	if (soundBtn.isClicked(sf::Mouse::Left, gData -> mWindow))
	{
		gData -> mMusic.switchPaused();
	}

}


