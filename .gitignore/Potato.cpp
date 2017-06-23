#include "stdafx.h"
#include "Potato.h"


Potato::Potato()
{
	Name="Ziemniak";
	Price=10;
}
Statistics^ Potato::getStatistics()
{
	return gcnew Statistics(5, 0, 5, 5, 0, 0, 0, 0);
}
