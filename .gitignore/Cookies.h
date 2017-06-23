#pragma once
#include "Food.h"
ref class Cookies:public Food
{
public:
	virtual Statistics^ getStatistics()override;
	Cookies(void);
};

