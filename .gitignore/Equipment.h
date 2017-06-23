#pragma once
#include "Item.h"
ref class Equipment
{
	const static int maxCapacity=4;
public:
	System::Collections::Generic::List<Item^>^ ToUse;
	System::Collections::Generic::List<Item^>^ InUse;
	Statistics^ use(int thing);
	Statistics^ wear(int clothes);
	Statistics^ unWear(int clothes);
	void add(Item^ item);
	void remove(Item^ item);
	Equipment(void);
};

