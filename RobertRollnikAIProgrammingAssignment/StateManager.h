#ifndef STATEMANAGER_H
#define STATEMANAGER_H

class State;

class StateManager
{
private:
	State* currentState;

public:
	StateManager();
	void setState(State* state);
	void update();
};

#endif
