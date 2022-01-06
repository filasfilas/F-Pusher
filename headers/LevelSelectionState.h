#pragma once

#include "State.h"
#include "Application.h"
#include "ResourceIdentifiers.h"
#include "SFML/Graphics.hpp"

#include <string>

class LevelSelectionState : public State
{
    public:
        LevelSelectionState (GlobalDataRef gData);

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
		sf::Text	levelText;
		sf::Texture texture;
		int	level;
		std::string	strLevel;
/*
		Button		exitBtn;
		Button		choseLevelBtn;
		Button		playBtn;
*/
};
