#pragma once
#include "Reward.h"
public ref class NameReward:public Reward
{
public:
	virtual void apply(Character^ character)override;
	NameReward(void);
};

