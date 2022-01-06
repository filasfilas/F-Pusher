#include "headers/Button.h"
#include "headers/Utility.h"

Button::Button()
{
}

void Button::setButton(sf::Sprite sprite, sf::Text text)
{
	mSprite = sprite;
	mText = text; 
	centerOrigin(mText);
	mText.setPosition(mSprite.getPosition());
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
	window.draw(mText);
}

bool Button::isClicked(sf::Mouse::Button button, const sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		int x = mSprite.getPosition().x - mSprite.getOrigin().x;
		int y = mSprite.getPosition().y - mSprite.getOrigin().y;
		sf::IntRect buttonRect(x, y, mSprite.getGlobalBounds().width, mSprite.getGlobalBounds().height);

		if(buttonRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}