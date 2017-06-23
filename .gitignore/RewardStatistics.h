#pragma once

#include "Reward.h"

public ref class RewardStatistics : Reward
{
public:
	RewardStatistics(void);
	virtual void apply(Character^ ch) override;
};