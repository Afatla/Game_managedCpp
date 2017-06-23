#pragma once
#include "ConsoleUserInterface.h"
#include "Map1.h"
public ref class Game abstract
{
private:
	UserInterface^ userInterface;
public:
	virtual Map^ createGame(int locations) abstract;
	virtual void start() abstract;
	property UserInterface^ UI
	{
		UserInterface^ get();
		void set(UserInterface^ value);
}
	Game(void);
};

