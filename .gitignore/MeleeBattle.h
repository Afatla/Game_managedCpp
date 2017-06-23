#pragma once
#include "Battle.h"
ref class MeleeBattle :
	public Battle
{
public:
	virtual void fight(Character^ character) override;
	
	MeleeBattle();
};

