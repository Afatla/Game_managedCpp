#include "stdafx.h"
#include "GoldReward.h"


GoldReward::GoldReward(void)
{
}
void GoldReward::apply(Character^ character)
{
	Statistics^ statistics=gcnew Statistics(0,0,0,0,0,0,0,50);
	character->Stats->add(statistics);
}
