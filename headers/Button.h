#pragma once

#include "SFML/Graphics.hpp"


class Button
{
	public:

		Button();
		
		void setButton(sf::Sprite sprite, sf::Text text);
		bool isClicked(sf::Mouse::Button button, const sf::RenderWindow& window);
		void draw(sf::RenderWindow& window);


	private:
		sf::Text	mText;
		sf::Sprite	mSprite;
};
