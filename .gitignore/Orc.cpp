#include "stdafx.h"
#include "Orc.h"


Orc::Orc(String^ des, Statistics^ st)
{
	this->description=des;
	this->statistics=st;
}
int Orc::baseMeleeAttack()
{
	return this->Stats->Agility * 2;
}
int Orc::baseRangeAttack()
{
	return this->Stats->Strength * 2;
}
int Orc::blockAttack()
{
	return this->Stats->HP * 2;
}
