#include "stdafx.h"
#include "Shop.h"
#include "ConsoleUserInterface.h"

Shop::Shop(String^ conf)
{
	this->availableItems=gcnew System::Collections::Generic::List<Item^>();
}
Shop::Shop(){}
System::Collections::Generic::List<Item^>^ Shop::Items::get()
{
	return availableItems;
}
void Shop::Items::set(System::Collections::Generic::List<Item^>^it)
{
	availableItems=it;
}

