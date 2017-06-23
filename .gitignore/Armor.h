#pragma once
#include "Wearable.h"
ref class Armor:public Wearable
{
public:
	virtual Statistics^ getStatistics()override;
	Armor(void);
};

