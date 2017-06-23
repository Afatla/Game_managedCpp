#include "stdafx.h"
#include "Cookies.h"


Cookies::Cookies(void)
{
	Price=5;
	Name="Cookies";
}

Statistics^ Cookies::getStatistics()
{
	Statistics^ s=gcnew Statistics(20, 5, 0, 0, 0, 0, 0, 0);
	return s;
}
