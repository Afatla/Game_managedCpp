#pragma once
#include "Game.h"
#include "Location1.h"
public ref class Game1:public Game
{
private:
	Location^ createLocation();

	Encounter^ createEncounter();

public:
	Game1(void);

	virtual Map^ createGame(int locations) override;
	virtual void start() override;
};

