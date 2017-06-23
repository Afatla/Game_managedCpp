#include "stdafx.h"
#include "Location.h"
#include "ConsoleUserInterface.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
Location::Location(String^ conf)
{
	this->configFile = conf;

	this->userInterface=gcnew ConsoleUserInterface();

	this->availableEncounters = gcnew List<Encounter^>();

	this->neighbourLocations = gcnew List<Location^>();

	auto lines = System::IO::File::ReadAllLines(this->configFile);

	this->Name = lines[0];

	this->Description = lines[1];
}

System::String^ Location::Name:: get()
{
	return this->name;
}
void Location::Name:: set(System::String^ value)
{
	this->name=value;
}
System::String^ Location::Description:: get()
{
	return this->description;
}
System::String^ Location::File::get()
{
	return this->configFile;
}
void Location::File:: set(System::String^ cf)
{
	this->configFile=cf;
}
void Location::Description::set(System::String^ value)
{
	this->description=value;
}
System::Collections::Generic::List<Encounter^>^ Location:: AvailableEncounters:: get()
{
	return this-> availableEncounters;
}
void Location:: AvailableEncounters:: set(System::Collections::Generic::List<Encounter^>^ ae)
{
	this-> availableEncounters=ae;
}
System::Collections::Generic::List<Location^>^ Location:: NeighbourLocations:: get()
{
	return this-> neighbourLocations;
}
void Location:: NeighbourLocations:: set(System::Collections::Generic::List<Location^>^ nl)
{
	this-> neighbourLocations=nl;
}

//adding the neighbourlocations
void Location::addNeighbour(Location^ location)
{
	this->NeighbourLocations->Add(location);
}
