#pragma once

#include "State.h"
#include "Application.h"
#include "ResourceIdentifiers.h"
#include "Definitions.h"
#include "SFML/Graphics.hpp"

class TitleState : public State
{
    public:
        TitleState (GlobalDataRef gData);

        void init();
        void handleInput(const sf::Event& event);
        void update (float dt);
        void draw(float dt );

    private:
        GlobalDataRef   gData;
        sf::Sprite  background;
		sf::Texture	texture;		

		sf::Text	titleText[4];
		


};
