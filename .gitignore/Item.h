#pragma once
#include "Statistics.h"
using namespace System;
ref class Item abstract
{
protected:
	int price;
	String^ name;
	Statistics^ stats;
public:
	virtual bool isWearable()=0;
	virtual Statistics^ getStatistics()=0;
	property int Price
	{
		int get();
		void set(int p);
	}
	property String^ Name
	{
		String^ get();
		void set(String^ n);
	}
	property Statistics^ Stats
	{
		Statistics^ get();
		void set(Statistics^);
	}
	Item(void);
};

