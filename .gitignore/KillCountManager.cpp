#include "stdafx.h"
#include "KillCountManager.h"

using namespace System;
using namespace System::Collections::Generic;
KillCountManager::KillCountManager()
{
	
}
void KillCountManager::addKills(int n)
{
	this->kills+=n;
	this->notifyAll();
}
void KillCountManager::Kills::set(int n)
{
	this->kills=n;
}
int KillCountManager::Kills::get()
{
	return kills;
}
void KillCountManager::notifyAll()
{
	String^ message;
	if(this->kills==4)
	{
		message=="Your reward!";
	}
	for each (AchievementListener^ listener in this->listeners)
	{
		listener->achievementUnlocked(message);
	}
}