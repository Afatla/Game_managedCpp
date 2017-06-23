#include "stdafx.h"
#include "NameReward.h"


NameReward::NameReward(void)
{
}
void NameReward::apply(Character^ character)
{
	character->Des+=" super";
	ConsoleUserInterface^ ui=gcnew ConsoleUserInterface();
	String^ data;
	data = System::IO::File::ReadAllText("NR.txt");
	ui->showMessage(data+ character->Des);
}
