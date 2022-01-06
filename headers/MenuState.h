#pragma once

#include "State.h"
#include "Application.h"
#include "Button.h"
#include "ResourceIdentifiers.h"
#include "SFML/Graphics.hpp"

class MenuState : public State
{
    public:
        MenuState (GlobalDataRef gData);

        void init();
        void handleInput(const sf::Event& event);
        void update (float dt);
        void draw(float dt );
        
		void stop();
		void resume();
		void pause();

    private:
        GlobalDataRef   gData;
        sf::Sprite  background;
		sf::Text	titleText;
		sf::Texture texture;

		Button		exitBtn;
		Button		choseLevelBtn;
		Button		playBtn;

};
