#include "stdafx.h"
#include "Opponent.h"
#include "WizardFactory.h"

Opponent::Opponent(Character^ c)
{
	this->character=c;
}
Opponent::Opponent()
{
}
int Opponent::getMaxMana()
{
	this->character->Des+=" gone bad";
	return this->character->getMaxMana()+5;
}
