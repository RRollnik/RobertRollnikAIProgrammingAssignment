#include "StateManager.h"
#include "State.h"

#include <iostream>

StateManager::StateManager()
{
	currentState = NULL;
}

void StateManager::setState(State* state)
{
	if(currentState != NULL)
	{
		delete currentState;
	}

	currentState = state;
}

void StateManager::update()
{
	if(currentState != NULL)
	{
		currentState->update();
	}
}