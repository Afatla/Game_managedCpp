#include "stdafx.h"
#include "Game.h"
#include "ConsoleUserInterface.h"
UserInterface^ Game::UI::get()
{
	return this->userInterface;
}

void Game::UI::set(UserInterface^ value)
{
	this->userInterface = value;
}
Game::Game()
{
	this->UI = gcnew ConsoleUserInterface();
}