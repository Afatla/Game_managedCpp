#include "stdafx.h"
#include "Encounter.h"


Encounter::Encounter(String^ conf)
{
	this->configFile=conf;
}
Encounter::Encounter(){}
String^ Encounter::File::get()
{
	return configFile;
}
void Encounter::File::set(String^ f)
{
	configFile=f;
}
UserInterface^ Encounter::UsInterface :: get()
{
	return this->userInterface;
}
void Encounter::UsInterface :: set(UserInterface^ value)
{
	this->userInterface=value;
}
