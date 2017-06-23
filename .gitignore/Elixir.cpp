#include "stdafx.h"
#include "Elixir.h"

Elixir::Elixir(void)
{
	Price=10;
	Name="Elixir";
}

Statistics^ Elixir::getStatistics()
{
	Statistics^ s=gcnew Statistics(0, 0, 10, 0, 10, 0, 0, 0);
	return s;
}
