#pragma once
#include "Location.h"
ref class Map
{
private:
	Location^ begin;
public:
	virtual void run(Character^ character) abstract;
	System::Collections::Generic::List<Location^>^ LocationsList;
	property Location^ Begin
	{
		Location^ get();
		void set(Location^ value);
	}
	Map(Location^);
	Map();
};

