#pragma once
#include "IInput.h"
#include "SaveData.h"
#include <iostream>
#include <string>
#include <vector>
#include "MenuItems.h"
#include "IInput.h"
#include "Words.h"
#include "Tests.h"

using namespace std;
using namespace ConsoleValidation;

class ConsoleMenuInterface {
private:
	static void RunSaveMenu(string& text, string& symbols, vector<string> result);
	static void ShowMainMenu();
	static void ShowSavingMenu();
	static void ShowRewriteMenu();
	static void ShowInputTypeMenu();
	static bool AskToRewrite();
	static void AskToMainMenu();
	static unique_ptr<IInput> AskInputType();
public:
	static void ShowGreetings();
	static void RunMainMenu();
};