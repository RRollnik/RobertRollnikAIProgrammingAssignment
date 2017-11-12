#include "AttackState.h"
#include "StateManager.h"
#include "IdleState.h"

#include <Windows.h>

#include <iostream>

AttackState::AttackState(StateManager* manager) : State(manager)
{
	ammo = 100;
}

void AttackState::update()
{
	if(ammo <= 0)
	{
		std::cout << "Out of ammo, changing state to jump..." << std::endl;
		Sleep(1000);
		manager->setState(new IdleState(manager));
	}
	else
	{
		std::cout << "Shoot" << std::endl;
		ammo--;
	}
}