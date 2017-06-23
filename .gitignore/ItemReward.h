#pragma once
#include "Reward.h"
#include "Armor.h"
#include"MagicCoat.h"
#include "Elixir.h"
#include "Potato.h"
#include "Opponent.h"
#include "Shield.h"
#include "Cookies.h"
ref class ItemReward :
	public Reward
{
private:
	System::Collections::Generic::List <Item^>^ rewards;
public:
	ItemReward();
	virtual void apply(Character^ ch) override;
	void make_Item();
};
