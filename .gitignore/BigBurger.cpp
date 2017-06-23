#include "stdafx.h"
#include "BigBurger.h"


BigBurger::BigBurger(void)
{
	Price=2;
	Name="BigBurger";
}

Statistics^ BigBurger::getStatistics()
{
	return gcnew Statistics(0, 0, 0, 0, 20, 0, 0, 0);
}
