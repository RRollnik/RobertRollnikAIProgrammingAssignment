#ifndef STATE_H
#define STATE_H

class StateManager;

class State
{
public:
	State(StateManager* manager);
	virtual ~State();

	virtual void update() = 0;

	State** self;

protected:
	StateManager* manager;

};

#endif