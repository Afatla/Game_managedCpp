#pragma once
#include "Location.h"
ref class Location1:public Location
{
	array<System::String^>^ data;
public:
	virtual Location^ run(Character^ character) override;
	
	Location1(String^ conf);
};

