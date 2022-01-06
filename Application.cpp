#include "headers/Application.h"
#include "headers/TitleState.h"
#include "headers/Definitions.h"


Application::Application()
{
    gData -> mWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), APP_NAME, sf::Style::Close);
    gData -> mWindow.setKeyRepeatEnabled(false);	
	sf::Image icon;
	icon.loadFromFile("media/images/icon.png");
	gData -> mWindow.setIcon(32, 32, icon.getPixelsPtr());

	loadResources();

    gData -> mStates.addState(StatePtr(new TitleState (gData))); //push TitleState in stack
}


void Application::run()
{       
	sf::Clock clock; 
	float timeSinceLastUpdate = 0; 
	bool repaint = false;

    while (gData -> mWindow.isOpen())
    {         
		timeSinceLastUpdate += (clock.restart()).asSeconds(); 
		while (timeSinceLastUpdate > TimePerFrame) 
		{ 
			timeSinceLastUpdate -= TimePerFrame; 
			repaint = true; 
            processInput();
            update(TimePerFrame); 

		} 
		if(repaint) 
        {
			render(TimePerFrame); 
			repaint = false;
     	}

		gData -> mStates.processStateChange();
        //close window if no active state
		if (gData -> mStates.isEmpty())
			gData -> mWindow.close();
    }
}


void Application::processInput()
{
	sf::Event event;

	while (gData -> mWindow.pollEvent(event))
	{
 		if (event.type == sf::Event::Closed)
		{gData -> mWindow.close();}
        //pass event into StateStack
        gData -> mStates.handleInput(event);
	}
}


void Application::render(float dt)
{
	gData -> mWindow.clear();
	gData -> mStates.draw(dt); // draw active states
//	mWindow.setView(mWindow.getDefaultView());
	gData -> mWindow.display();
}

void Application::update(float dt)
{
	gData -> mStates.update(dt);
}

void Application::loadResources()
{
    gData -> mAssets.loadTexture(Textures::TitleScreen, "media/images/background.png");
    gData -> mAssets.loadTexture(Textures::Tiles, "media/images/kenney_sokobanPack/Tilesheet/sokoban_tilesheet.png");
    gData -> mAssets.loadTexture(Textures::PlayButton, "media/images/Button.png");
	gData -> mAssets.loadTexture(Textures::ExitButton, "media/images/Button.png");
	gData -> mAssets.loadTexture(Textures::SmallMenu, "media/images/small_menu.png");

	gData -> mAssets.loadFont(Fonts::HUD, "media/fonts/PressStart2P-vaV7.ttf");
    gData -> mAssets.loadFont(Fonts::Main, "media/fonts/PressStart2P-vaV7.ttf");


 

}
