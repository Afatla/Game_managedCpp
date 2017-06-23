#pragma once

#include "Character.h"
#include "UserInterface.h"

public ref class Encounter abstract
{
private:
	System::String^ configFile;
	UserInterface^ userInterface;
public:
	virtual bool proceed(Character^ character)abstract;
	
	property String^ File
	{
		String^ get();
		void set(String^ f);
	}
	property UserInterface^ UsInterface 
	{
		UserInterface^ get();
		void set(UserInterface^ value);
	}
	Encounter(String^ conf);
	Encounter();
};