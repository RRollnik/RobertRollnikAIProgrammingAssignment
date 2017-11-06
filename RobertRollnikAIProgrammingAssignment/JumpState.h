#ifndef JUMPSTATE_H
#define JUMPSTATE_H

#include "State.h"

class JumpState : public State
{
public:
	JumpState(StateManager* manager);
	void update();

};

#endif