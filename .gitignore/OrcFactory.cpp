#include "stdafx.h"
#include "OrcFactory.h"
#include "Orc.h"

OrcFactory::OrcFactory(void)
{
}
Character^ OrcFactory::createCharacter()
{
	Character^ c= gcnew  Orc("Orc", gcnew Statistics(10,10,10,1,1,10,10,100));
	
	return c;
}
