#pragma once
#include "Statistics.h"
#include "Equipment.h"
using namespace System;
public ref class Character abstract
{
protected:
	String^ description;
	Statistics^ statistics;
	Equipment^ equipment;
public:
	int getMaxHp();
	int getMaxMana();
	virtual int baseMeleeAttack()=0;
	virtual int baseRangeAttack()=0;
	virtual int blockAttack()=0;
	void use(int thing);
	bool wear(int clothes);
	bool unWear(int clothes);
	property String^ Des
	{
		void set(String^ d);
		String^ get();
	}
	property Statistics^ Stats
	{
		void set(Statistics^ s);
		Statistics^ get();
	}
	property Equipment^ Eq
	{
		void set(Equipment^ e);
		Equipment^ get();
	}
	virtual void add_item(Item^ i);
	Character();
	Character(String^ des, Statistics^ st);
};

