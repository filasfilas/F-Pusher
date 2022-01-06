#pragma once

#include <memory>
#include "SFML/Graphics.hpp"
#include "ResourceManager.h"
#include "StateManager.h"
#include "MusicPlayer.h"

struct GlobalAppData
{
        sf::RenderWindow    mWindow;
        ResourceManager     mAssets;
        StateManager        mStates;
		MusicPlayer			mMusic;  
};

typedef std::shared_ptr<GlobalAppData> GlobalDataRef;

class Application
{
    public:
                Application();
		void    run();

    private:
        void    processInput();
        void    update(float dt);
        void    render(float dt);
        void    loadResources();

        const float     TimePerFrame =1.0f/60.0f;
        GlobalDataRef   gData  = std::make_shared<GlobalAppData>();
              
};
