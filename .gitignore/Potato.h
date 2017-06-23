#pragma once
#include "Food.h"
ref class Potato :
	public Food
{
public:
	Potato();

	virtual Statistics^ getStatistics() override;
};
