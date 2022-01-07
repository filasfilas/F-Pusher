#pragma once

#include "Application.h"
#include "SFML/Graphics.hpp"
#include "Button.h"
//#include "Definitions.h"


class HUD
{
	public:
		HUD(GlobalDataRef   gData);

		void draw();
		void update(int currLevel);
        void handleInput(const sf::Event& event);

	private:
        GlobalDataRef   gData;
		sf::Text		bottomText;
		sf::Text		upperText;	
		Button			soundBtn;		

		int				mLevel;

};
