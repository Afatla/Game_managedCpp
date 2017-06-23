#pragma once
#include "Wearable.h"
ref class Helm:public Wearable
{
public:
	virtual Statistics^ getStatistics()override;
	Helm(void);
};

