#include "stdafx.h"
#include "Shop1.h"
#include "ConsoleUserInterface.h"

#include "Armor.h"
#include "BigBurger.h"
#include "Shield.h"
#include "Elixir.h"
#include "Cookies.h"
#include "MagicCoat.h"
#include "Helm.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

Shop1::Shop1(String^ conf)
{
	this->File=conf;
	this->data=System::IO::File::ReadAllLines("Shop1.txt");
	this->Items=gcnew System::Collections::Generic::List<Item^>();
	this->Items->Add(gcnew Helm());
	this->Items->Add(gcnew Cookies());
	this->Items->Add(gcnew MagicCoat());
	this->Items->Add(gcnew Armor());
	this->Items->Add(gcnew Shield());
	this->Items->Add(gcnew BigBurger());
	this->Items->Add(gcnew Elixir());
}
void Shop1::trade(Character^ character)
{
	UserInterface^ ui = gcnew ConsoleUserInterface();
	if(character->Stats->Gold>=selectedItem->Price)
		{
			character->Eq->add(selectedItem);
			character->Stats->add(selectedItem->getStatistics());
			character->Stats->substract(gcnew Statistics(0,0,0,0,0,0,0,selectedItem->Price));
		}
		else
		{
			ui->showMessage(data[0]);
		}
		selectedItem = nullptr;
}
bool Shop1::proceed(Character^ character)
{
	auto question = this->data[1];

	List<String^>^ answers = gcnew List<String^>();

	for(;;)
	{
		answers->Clear();
		for each(Item^ item in this->Items)
		{
			answers->Add(item->Name);
		}
		answers->Add(this->data[2]);

		auto choice = this->UsInterface->askQuestion(question, answers);

		if (choice == answers->Count - 1)
		{
			return true;
		}
		else
		{
			this->selectedItem = this->Items[choice];
			this->trade(character);
		}
	}
}