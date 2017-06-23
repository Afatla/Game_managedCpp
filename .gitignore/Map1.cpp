#include "stdafx.h"
#include "Map1.h"
#include "ConsoleUserInterface.h"
#include "Location1.h"
#include "ConsoleUserInterface.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

Map1::Map1(Location^ location)
{
	this->Begin=location;
}
void Map1::run(Character^ character)
{
	UserInterface^ ui = gcnew ConsoleUserInterface();
	String^ data = System::IO::File::ReadAllText("Map1.txt");
	auto tempLocation = this->Begin;

	while(true)
	{
		if(character->Stats->HP<=0)
		{
			break;
		}
		else
		{
			ui->showMessage(data);
			tempLocation = tempLocation->run(character);
		}
	}
}
