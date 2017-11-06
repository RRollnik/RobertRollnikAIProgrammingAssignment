#include "JumpState.h"

#include <iostream>

JumpState::JumpState(StateManager* manager) : State(manager)
{

}

void JumpState::update()
{
	std::cout << "Jump update" << std::endl;
}