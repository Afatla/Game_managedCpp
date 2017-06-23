#include "stdafx.h"
#include "BasicShop.h"
#include "ConsoleUserInterface.h"

BasicShop::BasicShop()
{
}

void BasicShop::trade(Character^ ch)
{
	auto lines = System::IO::File::ReadAllLines("Shop.txt");
	String^ chooseProductQuestion = lines[1];
	auto Product_descriptions = gcnew System::Collections::Generic::List<String^>();
	UserInterface^ U_interface = gcnew ConsoleUserInterface();
	int choosenProduct;
	//StatisticGoldFactory^ PriceFactory = gcnew StatisticGoldFactory();
	Statistics^ Price;
	for each(Item^ i in Items)
	{
		Product_descriptions->Add(i->Name);
	}
	Product_descriptions->Add("Wróæ");
	for (;;)
	{
		choosenProduct=U_interface->askQuestion(chooseProductQuestion, Product_descriptions);
		if (choosenProduct == Items->Count)
		{
			break;
		}
		else if(ch->Stats->Gold - Items[choosenProduct]->Price > 0)
		{
			int price = Items[choosenProduct]->Price;
			ch->Stats->substract(gcnew Statistics(0,0,0,0,0,0,0,price));
			ch->Stats->add(Items[choosenProduct]->Stats);
			Delete_Item(Items[choosenProduct]);
			break;
		}
		else
		{
			U_interface->showMessage("Brak wystarczajacej liczby pieniedzy");
		}
	}
}

void  BasicShop::make_Item()
{
	auto random = gcnew System::Random();
	int reward_nbr = (int)random->Next(3, 15);
	int reward_kind = 0;
	Item^ it;
	for (int i = 0; i < reward_nbr; i++)
	{
		reward_kind = (int)random->Next(0, 5);
		switch (reward_kind)
		{
		case(0):
		{
			it = gcnew Armor;
			break;
		}
		case(1):
		{
			it = gcnew MagicCoat;
			break;
		}
		case(2):
		{

			it = gcnew Cookies;
			break;
		}
		case(3):
		{

			it = gcnew Potato;
			break;
		}
		case(4):
		{
			it = gcnew Elixir;
			break;
		}
		case(5):
		{
			it = gcnew Shield;
			break;
		}
		default:
			break;
		}
		Add_Item(it);
	}
}
void BasicShop::Add_Item(Item^ A)
{
	availableItems->Add(A);
}
void BasicShop::Delete_Item(Item^ A)
{
	availableItems->Remove(A);
}
