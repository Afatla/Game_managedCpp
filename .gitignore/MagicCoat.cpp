#include "stdafx.h"
#include "MagicCoat.h"


MagicCoat::MagicCoat(void)
{
	Price=20;
	Name="MagicCoat";
}

Statistics^ MagicCoat::getStatistics()
{
	return gcnew Statistics(0, 0, 0, 0, 0, 10, 0, 10);
}
