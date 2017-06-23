#include "stdafx.h"
#include "BonusEquipmentReward.h"
#include "Armor.h"
#include "BigBurger.h"

BonusEquipmentReward::BonusEquipmentReward(void)
{
}
void BonusEquipmentReward::apply(Character^ character)
{
	Item^ armor = gcnew Armor();
	Item^ bigburger = gcnew BigBurger();
	character->Eq->ToUse->Add(armor);
	character->Eq->ToUse->Add(bigburger);
	UserInterface^ ui=gcnew ConsoleUserInterface();
	String^ data;
	data = System::IO::File::ReadAllText("BER.txt");
	ui->showMessage(data);
}
