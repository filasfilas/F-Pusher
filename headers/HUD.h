#pragma once

#include "Application.h"
#include "SFML/Graphics.hpp"
//#include "Definitions.h"


class HUD
{
	public:
		HUD(GlobalDataRef   gData);

		void draw();
		void update(int currLevel);

	private:
        GlobalDataRef   gData;
		sf::Text		bottomText;
		sf::Text		upperText;			

		int				mLevel;

};
