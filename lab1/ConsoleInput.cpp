#include "IInput.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace SymbolsExt;

string ConsoleInput::InputText() {
	cout << "¬вод текста из консоли. ¬ведите пустую строку дл€ дл€ завершени€ ввода." << endl;
	cout << "¬ведите текст:" << endl;
	string line{};
	getline(cin, line);
	string text{};
	while (!line.empty()) {
		text += line + "\n";
		getline(cin, line);
	};

	return text;
}

string ConsoleInput::InputSymbols() {

	cout << "¬вод символов из консоли. ƒл€ завершени€ ввода нажмите Enter" << endl;
	cout << "¬ведите символы в одну строку:" << endl;
	string symbols;
	getline(cin, symbols);
	
	string uniqueSymbols = Symbols::GetUniqueSymbols(symbols);\

	return uniqueSymbols;
}

