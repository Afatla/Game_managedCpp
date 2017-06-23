#pragma once
#include "Item.h"
ref class Food abstract:public Item
{
public:
	virtual bool isWearable() override;
	virtual Statistics^ getStatistics()override=0;
	Food(void);
};

