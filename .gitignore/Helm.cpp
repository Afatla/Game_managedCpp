#include "stdafx.h"
#include "Helm.h"


Helm::Helm(void)
{
	Price=10;
	Name="Helm";
}

Statistics^ Helm::getStatistics()
{
	return gcnew Statistics(0, 0, 0, 0, 0, 1, 0, 2);
}