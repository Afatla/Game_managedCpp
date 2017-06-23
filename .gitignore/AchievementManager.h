#pragma once
#include "AchievementListener.h"

public ref class AchievementManager abstract
{
protected:
	System::Collections::Generic::List<AchievementListener^>^ listeners;
public:
	virtual void notifyAll() abstract;
	property System::Collections::Generic::List<AchievementListener^>^ Listeners
		{
			System::Collections::Generic::List<AchievementListener^>^ get();
		}
	AchievementManager();
};

