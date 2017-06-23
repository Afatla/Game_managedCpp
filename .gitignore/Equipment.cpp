#include "stdafx.h"
#include "Equipment.h"


Equipment::Equipment(void)
{
	this->ToUse=gcnew System::Collections::Generic::List<Item^>();
	this->InUse=gcnew System::Collections::Generic::List<Item^>();
}
Statistics^ Equipment::use(int i)
{
	if(i <= this-> ToUse->Count - 1)
	{

		if(ToUse[i]->isWearable())
		{
			return this->wear(i); //wearable
			
		}
		else
		{
			this->remove(ToUse[i]); //food
			return ToUse[i]->getStatistics();
		}
	}
}

Statistics^ Equipment::wear(int i)
{
	if(i <= this-> ToUse->Count - 1 && this-> InUse->Count <= this-> maxCapacity)
	{
		if(ToUse[i]->isWearable())
		{
			this-> remove(ToUse[i]);
			this-> InUse->Add(ToUse[i]);
			return ToUse[i]->getStatistics();
		}
	}
	
}

Statistics^ Equipment::unWear(int i)
{
	if (i <= this-> InUse->Count - 1)
	{
	
		this-> InUse->Remove( InUse[i]);
		this-> add( InUse[i]);
		return InUse[i]->getStatistics();
	}
	
}

void Equipment::add(Item^ item)
{
	 ToUse->Add(item);
}

void Equipment::remove(Item^ item)
{
	 ToUse->Remove(item);
}