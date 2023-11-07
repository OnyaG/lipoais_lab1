#pragma once
#include "MenuItems.h"
#include <string>

using namespace std;

namespace ConsoleValidation {
	class ConsoleInputValidation {
	public:

		static int GetInt();
		static string GetString();

		static mainMenuItem GetMainMenuItem();
		static savingMenuItem GetSavingMenuItem();
		static rewriteMenuItem GetRewriteMenuItem();
		static inputTypeMenuItem GetInputTypeMenuItem();
	};
}