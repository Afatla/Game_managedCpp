#pragma once
#include "Food.h"
ref class Elixir:public Food
{
public:
	virtual Statistics^ getStatistics()override;
	Elixir(void);
};

