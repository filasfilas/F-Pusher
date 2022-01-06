#pragma once

#include "State.h"
#include "Application.h"
#include "ResourceIdentifiers.h"
#include "SFML/Graphics.hpp"

class GameOverState : public State
{
    public:
        GameOverState (GlobalDataRef gData, std::string gameOverType); //Type - "won" or "loose"

        void init();
        void handleInput(const sf::Event& event);
        void update (float dt);
        void draw(float dt );

    private:
        GlobalDataRef   gData;
        sf::Sprite  background;
		sf::Text	overText;
		sf::Text	titleText;

};
