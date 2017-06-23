#pragma once
#include "Wearable.h"
ref class MagicCoat:public Wearable
{
public:
	virtual Statistics^ getStatistics()override;
	MagicCoat(void);
};

