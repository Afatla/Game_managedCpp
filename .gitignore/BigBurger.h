#pragma once
#include "Food.h"
ref class BigBurger:public Food
{
public:
	virtual Statistics^ getStatistics()override;
	BigBurger(void);
};

