#pragma once
#include "Wearable.h"
ref class Shield : public Wearable
{
public:
	Shield();
	virtual Statistics^ getStatistics() override;
};

