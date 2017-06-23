#include "stdafx.h"
#include "Battle2.h"
#include "ConsoleUserInterface.h"
#include "BonusEquipmentReward.h"
#include "OrcFactory.h"
#include "RatFactory.h"
#include "TrollFactory.h"
using namespace System::IO;
using namespace System::Collections::Generic;

Battle2::Battle2(void)
{
	this->data = System::IO::File::ReadAllLines("Battle2.txt");
	
}
void Battle2::fight(Character^ character)
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
			cf=gcnew RatFactory();
		}
		else
		{
			cf=gcnew TrollFactory();
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
			int attack=opponent->baseRangeAttack();
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
				character->Stats->HP-=opponent->baseMeleeAttack()-3-1-random_strength;
				}
				ui->showMessage(data[7]);
			}
			if(choose==4)
			{
				//message="Next opponent!";
				ui->showMessage(data[7]);
			}

			if(opponent->Stats->HP<=0&&character->Stats->HP>0)
			{
				counter++;
				//message="You won!";
				ui->showMessage(data[8]);
			}
			if(character->Stats->HP<=0)
			{
				//message="You lose!";
				ui->showMessage(data[9]);
				break;
			}	
		}
		
		if(killcountmanager->Kills==opponents->Count)
		{
			//message="Your reward!";
			//ui->showMessage(data[10]);
			this->reward=gcnew BonusEquipmentReward();
			reward->apply(character);
			
		}
			
}
bool Battle2 :: proceed(Character^ character)
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