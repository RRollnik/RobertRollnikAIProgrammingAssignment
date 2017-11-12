#ifndef IDLESTAE_H
#define IDLESTAE_H

#include "State.h"

class IdleState : public State
{
public:
	IdleState(StateManager* manager);
	void update();

};

#endif