#pragma once
#include <string>
public interface class AchievementListener
{
public:
	virtual void achievementUnlocked(System::String^ achievement) abstract;
};

