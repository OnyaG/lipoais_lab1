#include <iostream>
#include "MenuItems.h"
#include "InputValidation.h"

using namespace std;

template<typename T>
T GetInput() {
	T userInput;
	cin >> userInput;
	if (cin.fail()) {
		cout << "Недопустимое значение, введите снова." << endl;
		while (cin.fail()) {
			cin.clear(); // ?
			cin.ignore(INT_MAX, '\n'); // ?
			cin >> userInput;
		}
	}
	cin.ignore(INT_MAX, '\n');
	return userInput;
}

namespace ConsoleValidation {
	int ConsoleInputValidation::GetInt() {
		return GetInput<int>();
	}

	string ConsoleInputValidation::GetString() {
		return GetInput<string>();
	}

	mainMenuItem ConsoleInputValidation::GetMainMenuItem() {
		return static_cast<mainMenuItem>(GetInt());
	}

	savingMenuItem ConsoleInputValidation::GetSavingMenuItem() {
		return static_cast<savingMenuItem>(GetInt());
	}

	rewriteMenuItem ConsoleInputValidation::GetRewriteMenuItem() {
		return static_cast<rewriteMenuItem>(GetInt());
	}

	inputTypeMenuItem ConsoleInputValidation::GetInputTypeMenuItem() {
		return static_cast<inputTypeMenuItem>(GetInt());
	}
}