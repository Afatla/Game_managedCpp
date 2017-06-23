#pragma once
#include "Statistics.h"
#include "Opponent.h"
ref class Rat:public Opponent
{
public:
	virtual int baseMeleeAttack()override;
	virtual int baseRangeAttack()override;
	virtual int blockAttack()override;
	Rat(System::String^ des, Statistics^ st);
};

