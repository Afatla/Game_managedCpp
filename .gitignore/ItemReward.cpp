#include "stdafx.h"
#include "ItemReward.h"


ItemReward::ItemReward()
{
	make_Item();
}
 void ItemReward::apply(Character^ ch)
{
	 for each(Item^ i in rewards)
	 {
		 ch->add_item(i);
	 }
}

 void  ItemReward::make_Item()
 {
	 auto random = gcnew System::Random();
	 int reward_nbr =(int)random->Next(3, 8);
	 int reward_kind = 0;
	 Item^ it;
	 for (int i = 0; i < reward_nbr; i++)
	 {
		 reward_kind= (int)random->Next(0, 5);
		 switch (reward_kind)
		 {
		 case(0):
		 {
			 it = gcnew Armor;
			 break;
		 }
		 case(1):
		 {
			 it = gcnew Cookies;
			 break;
		 }
		 case(2):
		 {

			 it = gcnew MagicCoat;
			 break;
		 }
		 case(3):
		 {

			 it = gcnew Potato;
			 break;
		 }
		 case(4):
		 {
			 it = gcnew Elixir;
			 break;
		 }
		 case(5):
		 {
			 it = gcnew Shield;
			 break;
		 }
		 default:
			 break;
		 }
		 rewards->Add(it);
	 }
 }
