#include "stdafx.h"
#include "Elf.h"


Elf::Elf(String^ des, Statistics^ stats)
{
	this->description=des;
	this->statistics=stats;
	this->equipment = gcnew Equipment();
}
int Elf::baseMeleeAttack()
{
	return this->Stats->Mana * 7;
}
int Elf::baseRangeAttack()
{
	return this->Stats->Strength * 7;
}
int Elf::blockAttack()
{
	return this->Stats->HP * 7;
}