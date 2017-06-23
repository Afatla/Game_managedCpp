#pragma once

#include "Character.h"

public ref class Opponent abstract : public Character
{
protected:
	Character^ character;
public:
	virtual int baseMeleeAttack()override=0;
	virtual int baseRangeAttack()override=0;
	virtual int blockAttack()override=0;
	int getMaxMana();
	Opponent();
	Opponent(Character^ c);
};