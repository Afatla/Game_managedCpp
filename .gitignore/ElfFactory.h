#pragma once
#include "CharacterFactory.h"
ref class ElfFactory:public CharacterFactory
{
public:
	virtual Character^ createCharacter();
	ElfFactory(void);
};

