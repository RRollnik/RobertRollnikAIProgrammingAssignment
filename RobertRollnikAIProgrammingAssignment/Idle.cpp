#include "IdleState.h"

#include <iostream>

IdleState::IdleState(StateManager* manager) : State(manager)
{

}

void IdleState::update()
{
	std::cout << "Idle" << std::endl;
}