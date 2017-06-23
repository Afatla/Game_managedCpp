#include "stdafx.h"
#include "Battle.h"
using namespace System::IO;
using namespace System::Collections::Generic;

Battle::Battle(void)
{
	this->opponents=gcnew List<Character^>();
}
String^ Battle::Name::get()
{
	return this->name;
}
void Battle::Name::set(System::String^ value)
{
	this->name=value;
}
String^ Battle::Description::get()
{
	return this->description;
}
void Battle::Description::set(System::String^ value)
{
	this->description=value;
}
Reward^Battle::Rew:: get()
{
	return this->reward;
}
void Battle::Rew::set( Reward^ value)
{
	this->reward=value;
}
System::Collections::Generic::List<Character^>^ Battle::Opponents::get()
{
	return this->opponents;
}
