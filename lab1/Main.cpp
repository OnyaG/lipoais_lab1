#include <iostream>
#include <Windows.h>
#include "ConsoleMenuInterface.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ConsoleMenuInterface::RunMainMenu();
}