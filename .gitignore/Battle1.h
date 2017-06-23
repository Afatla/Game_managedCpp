#pragma once
#include "Battle.h"
ref class Battle1:public Battle
{
	array<System::String^>^ data;
public:
	virtual void fight(Character^ character)override;
	virtual bool proceed(Character^ c)override;
	Battle1(void);
};

