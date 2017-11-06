#ifndef ATTACKSTATE_H
#define ATTACKSTATE_H

#include "State.h"

class AttackState : public State
{
private:
	int ammo;

public:
	AttackState(StateManager* manager);
	void update();

};

#endif