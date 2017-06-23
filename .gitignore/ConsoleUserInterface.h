#pragma once

#include "UserInterface.h";
#include "AchievementListener.h"
public ref class ConsoleUserInterface : public UserInterface, public AchievementListener
	{
	public:
		virtual int askQuestion(System::String^ question, System::Collections::Generic::List<System::String^>^ answers) override;
		virtual void showMessage(System::String^ message) override;
		virtual void achievementUnlocked(System::String^ message) override;
		ConsoleUserInterface(void);
	};