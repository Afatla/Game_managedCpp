#pragma once
#include "AchievementManager.h"
public ref class KillCountManager:public AchievementManager
{
	int kills;
public:
	void addKills(int n);
	property int Kills 
		{
			int get();
			void set(int value);
		}
	virtual void notifyAll()override;
	KillCountManager();
};

