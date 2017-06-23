#include "stdafx.h"
#include "Shield.h"


Shield::Shield()
{
	Name="Tarcza";
	Price=40;
}
Statistics^ Shield::getStatistics()
{
	return gcnew Statistics(0, 5, 0, 0, 10, 15, 0, 0);
}
