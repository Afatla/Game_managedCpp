#include "stdafx.h"
#include "Character.h"


Character::Character(String^ des, Statistics^ st)
{
	this->Des = des;

	this->Stats = st;

	this->equipment = gcnew Equipment();

}
Character::Character()
{
}
int Character::getMaxHp()
{
	return this->Stats->Toughness * 5;
}
int Character::getMaxMana()
{
	return this->Stats->Inteligence * 5;
}

void Character::use(int thing)
{
	this->equipment->use(thing);
	if(equipment->ToUse[thing]->isWearable()==false)
	{
	Stats->add(this->equipment->ToUse[thing]->getStatistics());
	}
}

bool Character::wear(int clothes)
{
	if(equipment->ToUse->Count>0&&Stats->Gold>=equipment->ToUse[clothes]->getStatistics()->Gold)
	{
		this->equipment->wear(clothes);
		this->Stats->add(equipment->ToUse[clothes]->getStatistics());
		return true;
	}
	else
	{
		return false;
	}
}

bool Character::unWear(int clothes)
{
	if(this->equipment->InUse->Count>0)
	{
		this->equipment->unWear(clothes);
		this->Stats->substract(equipment->InUse[clothes]->getStatistics());
		return true;
	}
	else
	{
		 return false;
	}
}

void Character::Stats::set(Statistics^ s)
{
	this->statistics=s;
}
Statistics^ Character::Stats::get()
{
	return this->statistics;
}
void Character::Eq::set(Equipment^ e)
{
	this->equipment=e;
}
Equipment^ Character::Eq::get()
{
	return this->equipment;
}
void Character::Des::set(String^ d)
{
	this->description=d;
}
String^ Character::Des::get()
{
	return this->description;
}
void Character::add_item(Item^ i)
{
	Eq->add(i);
}