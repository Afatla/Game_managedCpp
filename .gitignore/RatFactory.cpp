#include "stdafx.h"
#include "RatFactory.h"

#include "Rat.h"
RatFactory::RatFactory()
{
}
Character^ RatFactory::createCharacter()
{
	return gcnew Rat("Szczur", gcnew Statistics(20, 0, 0, 5, 5, 0, 0, 0));
}