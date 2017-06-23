#include "stdafx.h"
#include "Battle1.h"
#include "ConsoleUserInterface.h"
#include "NameReward.h"
#include "OrcFactory.h"
#include "WitchFactory.h"
#include "VampireFactory.h"
using namespace System::IO;
using namespace System::Collections::Generic;

Battle1::Battle1(void)
{
	this->data = System::IO::File::ReadAllLines("Battle1.txt");
	
}
void Battle1::fight(Character^ character)
{
	Random^ rand = gcnew Random();
	CharacterFactory^ cf;
	KillCountManager^ killcountmanager = gcnew KillCountManager();
	for(int i = 0; i<3;i++)
	{
	
		int random=rand->Next(1,3);
		if(random==1)
		{
			cf=gcnew OrcFactory();
		}
		else if(random==2)
		{
			cf=gcnew WitchFactory();
		}
		else
		{
			cf=gcnew VampireFactory();
		}
		Character^ opponent=cf->createCharacter();
		this->Opponents->Add(opponent);
	}
		List<String^>^ answers=gcnew List<String^>();
		int counter=0;
		killcountmanager->Kills=counter;
		int choose=0;
		UserInterface^ ui = gcnew ConsoleUserInterface();
		ui->showMessage(data[0]);
		int round=1;
		ui->showMessage("1. "+data[3]);
		ui->showMessage("2. "+data[4]);
		ui->showMessage("3. "+data[5]);
		for each(Opponent^ opponent in opponents)
		{
			Random^ rand = gcnew Random();
			round++;
			int random_strength=rand->Next(1,round);
			int random_distance=rand->Next(1,2);
			
			ui->showMessage(opponent->Des);
			int attack=opponent->baseMeleeAttack();
			String^ question = data[2];
			
			answers->Add(this->data[3]);
			answers->Add(this->data[4]);
			answers->Add(this->data[5]);
			do
			{
				
				choose=ui->askQuestion(question, answers);
				
				if(choose!=1&&choose!=2&&choose!=3&&choose!=4)
					{
					ui->showMessage(data[6]);
					}
			}while(choose!=1&&choose!=2&&choose!=3&&choose!=4);

			answers->Clear();
			if(choose==1)
			{
				if(random_distance==1)
				{
				opponent->Stats->HP-=character->baseMeleeAttack()-random_strength;
				character->Stats->HP-=opponent->baseMeleeAttack()-random_strength;
				}
				else
				{
				opponent->Stats->HP-=character->baseMeleeAttack()-random_strength-1;
				character->Stats->HP-=opponent->baseMeleeAttack()-random_strength-1;
				}
				ui->showMessage(data[7]);
			}
			else if(choose==2)
			{
				if(random_distance==1)
				{
				opponent->Stats->HP-=-character->baseRangeAttack()-random_strength;
				character->Stats->HP-=opponent->baseMeleeAttack()-random_strength;
				}
				else
				{
				opponent->Stats->HP-=-character->baseRangeAttack()-random_strength-1;
				character->Stats->HP-=opponent->baseMeleeAttack()-random_strength-1;
				}
				ui->showMessage(data[7]);
			}
			else if(choose==3)
			{
				if(random_distance==1)
				{
				character->Stats->HP-=opponent->baseMeleeAttack()-3-random_strength;
				}
				else
				{
				character->Stats->HP-=opponent->baseMeleeAttack()-4-random_strength;
				}
				ui->showMessage(data[7]);
			}
			if(choose==4)
			{
				ui->showMessage(data[7]);
			}
	
			if(opponent->Stats->HP<=0&&character->Stats->HP>0)
			{
				killcountmanager->addKills(1);
				ui->showMessage(data[8]);
			}
			if(character->Stats->HP<=0)
			{
				ui->showMessage(data[9]);
				break;
			}	
		}
		ui->showMessage(data[7]);
		if(killcountmanager->Kills==opponents->Count)
		{
			//ui->showMessage(data[10]);
			this->reward=gcnew NameReward();
			reward->apply(character);
		}
			
}
bool Battle1 :: proceed(Character^ character)
{
	if(character->Stats->HP<=0)
	{
		return false;
	}
	else
	{
		this->fight(character);
		return true;
	}
}