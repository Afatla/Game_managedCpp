// GameCLR.cpp : main project file.

#include "stdafx.h"
#include "WizardFactory.h"
#include "Orc.h"
#include "Location1.h"
#include "Map1.h"
#include "Game1.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

int main(array<System::String ^> ^args)
{
	Game^ game = gcnew Game1();
	game->start();
	Console::ReadKey();
    return 0;
}
