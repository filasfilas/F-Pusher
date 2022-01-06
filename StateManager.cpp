#include "headers/StateManager.h"

StateManager::StateManager ()
: mAction (NONE)
{
}


StatePtr &StateManager::getActiveState ()
{
    return mStateStack.back();
}

void StateManager::addState (StatePtr state)
{
    newState = std::move(state);
    mAction = ADD;
}

void StateManager::replaceState (StatePtr state)
{
    newState = std::move(state);
    mAction = REPLACE;
}

void StateManager::replaceAllStates (StatePtr state)
{
    newState = std::move(state);
    mAction = REPLACEALL;
}

void StateManager::removeState ()
{
    mAction = REMOVE;
}

void StateManager::processStateChange ()
{
    if (mAction == NONE)
        return;

    if (mAction == ADD)
    {
        if (!mStateStack.empty())
            mStateStack.back() -> pause();
            
        mStateStack.push_back(std::move(newState));
        mStateStack.back() -> init();
    }

    if (mAction == REPLACE)
    {
        if (!mStateStack.empty())
		{
			mStateStack.back() -> stop();
            mStateStack.pop_back();
		}
            
        mStateStack.push_back(std::move(newState));
        mStateStack.back() -> init();
    }

    if (mAction == REPLACEALL)
    {
        while (!mStateStack.empty())
		{
			mStateStack.back() -> stop();
            mStateStack.pop_back();
		}
            
        mStateStack.push_back(std::move(newState));
        mStateStack.back() -> init();
    }

    if (mAction == REMOVE)
    {
        if (!mStateStack.empty())
		{
			mStateStack.back() -> stop();
            mStateStack.pop_back();
		}
        if (!mStateStack.empty())
            mStateStack.back() -> resume();
    }
    
    mAction = NONE;
}


void StateManager::update (float dt)
{
//    for (StatePtr state:mStateStack)
      mStateStack.back() -> update(dt);
}

void StateManager::draw(float dt)
{
	for (auto itr = mStateStack.begin(); itr != mStateStack.end(); itr++)
	{
    	(*itr) -> draw(dt);
	}
}

void StateManager::handleInput(sf::Event& event)
{
//    for (StatePtr &state:mStateStack)
      mStateStack.back() -> handleInput(event);
}

bool StateManager::isEmpty()
{
    return mStateStack.empty();
}

