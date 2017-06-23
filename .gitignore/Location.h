#pragma once
#include "Encounter.h"
#include "UserInterface.h"
#include "ConsoleUserInterface.h"
public ref class Location abstract
{
protected:
	System::String^ name;
	System::String^ description;
	System::String^ configFile;
	System::Collections::Generic::List<Location^>^ neighbourLocations;
	System::Collections::Generic::List<Encounter^>^ availableEncounters;
	UserInterface^ userInterface;

public:
	virtual Location^ run(Character^ character) abstract;
	void addNeighbour(Location^ );
		property System::String^ Name 
		{
			System::String^ get();
			void set(System::String^ value);
		}
		property System::String^ Description
		{
			System::String^ get();
			void set(System::String^ value);
		}
		property System::String^ File
		{
			System::String^ get();
			void set(System::String^ cf);
		}
		property System::Collections::Generic::List<Encounter^>^  AvailableEncounters
		{
			System::Collections::Generic::List<Encounter^>^ get();
			void set(System::Collections::Generic::List<Encounter^>^ ae);
		}
		property System::Collections::Generic::List<Location^>^ NeighbourLocations
		{
			System::Collections::Generic::List<Location^>^ get();
			void set(System::Collections::Generic::List<Location^>^ nl);
		}

		Location(String^ conf);
	};
