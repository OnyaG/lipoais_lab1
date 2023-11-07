#include "IInput.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace SymbolsExt;

string ConsoleInput::InputText() {
	cout << "���� ������ �� �������. ������� ������ ������ ��� ��� ���������� �����." << endl;
	cout << "������� �����:" << endl;
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

	cout << "���� �������� �� �������. ��� ���������� ����� ������� Enter" << endl;
	cout << "������� ������� � ���� ������:" << endl;
	string symbols;
	getline(cin, symbols);
	
	string uniqueSymbols = Symbols::GetUniqueSymbols(symbols);\

	return uniqueSymbols;
}

