#include "stdafx.h"
#include "Game1.h"
#include "WizardFactory.h"
#include "Location1.h"
#include "Shop1.h"
#include "Battle1.h"
#include "Battle2.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
Game1::Game1(void)
{
	this->UI = gcnew ConsoleUserInterface();
}
Map^ Game1::createGame(int locations)
{
	
	auto location1 = this->createLocation();
	Map^ map1 = gcnew Map1(location1);
	map1->LocationsList=gcnew List<Location^>();
	for(int i = 0; i < locations; i++)
	{
		auto location = this->createLocation();
		map1->LocationsList->Add(location);
	}
	return map1;
}
void Game1::start()
{
	CharacterFactory^ wizardfactory = gcnew WizardFactory();
	Character^ player = wizardfactory->createCharacter();
	UI->showMessage("You are a "+player->Des);
	Map^ map = this->createGame(9);
	map->run(player);
}
Location^ Game1::createLocation()
{
	Location^ location1 = gcnew Location1("Location1.txt");
	Location^ location2 = gcnew Location1("Location1.txt");
	Location^ location3 = gcnew Location1("Location1.txt");
	Location^ location4 = gcnew Location1("Location1.txt");

	location1->addNeighbour(location2);
	location1->addNeighbour(location3);
	location3->addNeighbour(location1);
	location3->addNeighbour(location2);
	location2->addNeighbour(location4);
	location2->addNeighbour(location1);
	location2->addNeighbour(location3);
	location4->addNeighbour(location2);
	auto random = gcnew Random();

	for(int i = 0; i < 2; i++)
	{
		Encounter^ encounter = this->createEncounter();
		location1->AvailableEncounters->Add(encounter);
	}
	return location1;
}
Encounter^ Game1::createEncounter()
{
	auto random = gcnew Random();
	Encounter^ encounter;
	
	int choice = random->Next(0, 3);
	if(choice == 0)
	{
		encounter = (gcnew Shop1("Shop1.txt"));
	}
	else if(choice==1)
	{
		encounter = (gcnew Battle1());
	}
	else if(choice==2)
	{		
		encounter = (gcnew Battle2());
	}
	return encounter;
}