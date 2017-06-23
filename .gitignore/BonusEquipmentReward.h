#pragma once
#include "Reward.h"
public ref class BonusEquipmentReward:public Reward
{
public:
	virtual void apply(Character^ character)override;
	BonusEquipmentReward(void);
};

