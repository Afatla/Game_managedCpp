#pragma once
#include"Opponent.h"
public ref class Orc:public Opponent
{
public:
	virtual int baseMeleeAttack()override;
	virtual int baseRangeAttack()override;
	virtual int blockAttack()override;
	Orc(String^ des, Statistics^ st);
};

