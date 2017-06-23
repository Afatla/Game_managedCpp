#pragma once
#include "Map.h"

ref class Map1:public Map
{

public:
	virtual void run(Character^ character) override;
	
	Map1(Location^);
};

