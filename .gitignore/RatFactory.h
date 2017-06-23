#pragma once
#include "CharacterFactory.h"
public ref class RatFactory :
	public CharacterFactory
{
public:
	RatFactory();
	virtual Character^ createCharacter() override;
};

