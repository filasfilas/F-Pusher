#pragma once

#include "State.h"
#include "Application.h"
#include "LevelManager.h"
#include "HUD.h"
#include "ResourceIdentifiers.h"
#include "SFML/Graphics.hpp"

#include <vector>
#include <string>


class GameState : public State
{
    public:
        GameState (GlobalDataRef gData, int level);

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

		int currLevel;
	
		LevelManager	mLevel;
		HUD				mHUD;

		Direction	moveDirection;

};
