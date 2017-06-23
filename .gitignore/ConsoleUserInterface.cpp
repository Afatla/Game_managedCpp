#include "stdafx.h"
#include "ConsoleUserInterface.h"
using namespace System;
using namespace System::Collections::Generic;

ConsoleUserInterface::ConsoleUserInterface(void)
{
}

int ConsoleUserInterface::askQuestion(String^ question, List<String^>^ answers)
{
	Console::WriteLine(question);

		for(int i = 0; i < answers->Count; i++)
		{
			Console::WriteLine(answers[i]);
		}

	int choice;

	do
	{
		choice = Convert::ToInt32(Console::ReadLine());
	} 
	while (choice > answers->Count - 1);

	return choice;
}

void ConsoleUserInterface::showMessage(String^ message)
{
	Console::WriteLine(message);
}
void ConsoleUserInterface::achievementUnlocked(String^ message)
{

}
