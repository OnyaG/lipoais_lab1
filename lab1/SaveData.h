#pragma once
#include <iostream>
#include <string>
#include "MenuItems.h"
#include <filesystem>
#include <fstream>
#include "InputValidation.h"

class SaveData {
private:
	bool AskRewrite();
	bool Check(std::string);
public:
	void Saving(std::string& strForSave);
};