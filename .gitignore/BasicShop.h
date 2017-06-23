#pragma once
#include "Shop.h"
#include "Armor.h"
#include "Cookies.h"
#include "Potato.h"
#include "Elixir.h"
#include "MagicCoat.h"
#include "Shield.h"
ref class BasicShop :
	public Shop
{
public:
	BasicShop();
	virtual void trade(Character^ ch) override;
	void Add_Item(Item^);
	void Delete_Item(Item^ A);
	void make_Item() ;
};

