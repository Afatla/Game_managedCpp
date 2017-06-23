#pragma once
#include "CharacterFactory.h"
ref class OrcFactory:public CharacterFactory
{
public:
	virtual Character^ createCharacter();
	OrcFactory(void);
};

