#pragma once
#include "Shop.h"
public ref class Shop1:public Shop
{
public:
	Shop1(String^ conf);
	virtual void trade(Character^ character)override;
	virtual bool proceed(Character^ character)override;
};

