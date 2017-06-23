#include "stdafx.h"
#include "RewardStatistics.h"

RewardStatistics::RewardStatistics(void){}

void RewardStatistics::apply(Character^ ch)
{
	Statistics rewardStat(3, 1, 0, 2, 0, 1, 1, 15);
	ch->Stats->add(%rewardStat);
	//return true;
}
