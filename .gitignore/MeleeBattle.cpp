#include "stdafx.h"
#include "MeleeBattle.h"
#include "ConsoleUserInterface.h"
#include "Reward.h"
#include "ItemReward.h"
void MeleeBattle::fight(Character ^ character)
{
	auto file = System::IO::File::ReadAllLines(File);
	System::Random^ rand = gcnew System::Random();
	double alfaRate = (double)rand->Next(0.5, 1.5);//random variable
	System::Collections::Generic::List<System::String^>^ opponentsDescription;
	System::Collections::Generic::List<System::String^>^ attacanswer = gcnew System::Collections::Generic::List<System::String^>();
	System::String^ attacquestion;
	System::Collections::Generic::List<System::String^>^ chooseanswer = gcnew System::Collections::Generic::List<System::String^>();
	System::String^ choosequestion;
	while (true)
	{
		ConsoleUserInterface^ user = gcnew ConsoleUserInterface();
		int index = 0;
		int opponent = user->askQuestion(choosequestion, chooseanswer);
		System::String^ choosingopponent = opponentsDescription[opponent];
		while (index < Opponents->Count)
		{
			if (Opponents[index]->Des == choosingopponent) {
				break;
			}
			else index++;
		}
		Statistics^ opponentstatistic = Opponents[index]->Stats;
		int action = user->askQuestion(attacquestion, attacanswer);//what kind of attac user want to use
		if (action == 1)
		{
			//baseMelleeAtack
			int attacPower = character->baseMeleeAttack()*alfaRate;//user use range attac
			opponentstatistic->HP - attacPower;
			if (opponentstatistic->HP > 0)
			{
				attacPower = Opponents[index]->baseMeleeAttack()*alfaRate;
				character->Stats->HP - attacPower;
			}

		}
		if (action == 2)
		{
			//use screen
			int characterHidePower = character->blockAttack()*alfaRate;
			character->Stats->HP + characterHidePower;
			int opponentHidePower = Opponents[index]->blockAttack()*alfaRate;
			opponentstatistic->HP + opponentHidePower;
			break;
		}
		if (action = 3)
		{
			//use sword
			System::Random^ rand = gcnew System::Random();
			int swordPower = rand->Next(10, 30);
			int attacPower = character->baseRangeAttack() + swordPower;
			opponentstatistic->HP - attacPower;
			if (opponentstatistic->HP > 0)
			{
				attacPower = Opponents[index]->baseRangeAttack() + swordPower;
				character->Stats->HP - attacPower;
			}
			break;
		}
		
		if (Opponents[index]->Stats->HP < 0)
		{
			Opponents->Remove(Opponents[index]);
		}
		if (Opponents->Count == 0)
		{
			Reward^ reward=gcnew ItemReward();
			reward->apply(character);
			break;
		}
		if (character->Stats->HP <= 0)
		{
			System::Console::WriteLine("Game over");
		}
	}
}

MeleeBattle::MeleeBattle():Battle()
{
}
