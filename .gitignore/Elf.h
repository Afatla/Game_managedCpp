#pragma once
#include "Character.h"
ref class Elf:public Character
{
public:
	virtual int baseMeleeAttack()override;
	virtual int baseRangeAttack()override;
	virtual int blockAttack()override;
	Elf(String^ description, Statistics^ stats);
};
