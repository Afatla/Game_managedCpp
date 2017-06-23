#include "stdafx.h"
#include "Rat.h"


Rat::Rat(System::String^ des, Statistics^ stats)
{
	this->description=des;
	this->statistics=stats;
}
int Rat::baseMeleeAttack()
{
	return this->Stats->Mana * 7;
}
int Rat::baseRangeAttack()
{
	return this->Stats->Strength * 7;
}
int Rat::blockAttack()
{
	return this->Stats->HP * 7;
}
