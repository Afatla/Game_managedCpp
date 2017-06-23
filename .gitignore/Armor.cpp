#include "stdafx.h"
#include "Armor.h"


Armor::Armor(void)
{
	Price=20;
	Name="Armor";
}

Statistics^ Armor::getStatistics()
{
	return gcnew Statistics(0, 0, 0, 5, 0, 5, 0, 5);
}
