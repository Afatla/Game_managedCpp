#pragma once
#include "Reward.h"
public ref class GoldReward:public Reward
{
public:
	virtual void apply(Character^ character)override;
	GoldReward(void);
};

