#include "stdafx.h"
#include "Location1.h"
#include "Map1.h"
#include "ConsoleUserInterface.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

Location1::Location1(String^ conf): Location(conf)
{
	this->data = System::IO::File::ReadAllLines(conf);

	this->Name = this->data[0];

	this->Description = this->data[1];
}

Location^ Location1::run(Character^ character)
{
	auto question = this->data[2];
	int number=-1;
	List<String^>^ answers = gcnew List<String^>();

	for each(Location^ location in this->NeighbourLocations)
	{
		number++;
		String^ num = number.ToString();
		answers->Add(num+this->data[3] + " " + location->Name);
	}
	
	for(int i = number; i < this->AvailableEncounters->Count; i++)
	{
		answers->Add((i+1)+" "+this->data[4]);
	}
	while(character->Stats->HP>=0)
	{
		int choice = this->userInterface->askQuestion(question, answers);

		if (choice >= 0 && choice < this->NeighbourLocations->Count)
		{
			return this->NeighbourLocations[choice];
		}
		else
		{
			this->AvailableEncounters[choice - this->NeighbourLocations->Count]->proceed(character);
		}
	}
	
}
