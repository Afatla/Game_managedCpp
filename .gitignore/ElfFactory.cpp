#include "stdafx.h"
#include "ElfFactory.h"
#include "Elixir.h"
#include "Armor.h"
#include "Elf.h"
ElfFactory::ElfFactory(void)
{
}
Character^ ElfFactory::createCharacter()
{

	Character^ c = gcnew  Elf("Elf", gcnew Statistics(5,10,7,6,8,5,5,50));
	return c;
}
