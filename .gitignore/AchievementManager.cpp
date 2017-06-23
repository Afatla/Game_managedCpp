#include "stdafx.h"
#include "AchievementManager.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

AchievementManager::AchievementManager()
{
	this->listeners=gcnew List<AchievementListener^>();
}
List<AchievementListener^>^ AchievementManager::Listeners::get()
{
	return this->listeners;
}