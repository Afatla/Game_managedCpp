#pragma once

#include "Opponent.h"
#include "Encounter.h"
#include "Reward.h"
#include "Shop.h"
#include "KillCountManager.h"
#include "FormsUserInterface.h"
public ref class Battle abstract : public Encounter
	{
	protected:
		System::String^ name;
		System::String^ description;
		Reward^ reward;
		System::Collections::Generic::List<Character^>^ opponents;

	public:
		Battle();

		virtual void fight(Character^ character) abstract;

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

		property Reward^ Rew
		{
			 Reward^ get();
			void set( Reward^ value);
		}

		property System::Collections::Generic::List<Character^>^ Opponents 
		{
			System::Collections::Generic::List<Character^>^ get();
		}
		virtual bool proceed(Character^ character)override=0;
	};