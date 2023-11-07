#include "IInput.h"
#include <vector>
#include <filesystem>
#include <fstream>
#include <iostream>
#include "InputValidation.h"


using namespace std;
using namespace ConsoleValidation;
using namespace SymbolsExt;

bool FileInput::CheckValidDir(string& dir) {
	try {
		static_cast<void>(std::filesystem::is_regular_file(dir));
	}
	catch (...) {
		std::cout << "������ ����������. ���� � ����� �����������" << std::endl;
		return false;
	}
	return true;
}

string FileInput::InputText() {

	string dir;
	do {
		cout << "������� ���� ���������� �����: ";
		dir = ConsoleInputValidation::GetString();
	} while (!CheckValidDir(dir));

	ifstream inputStream{};

	inputStream.open(dir);
	if (!inputStream.is_open()) {
		inputStream.close();
		throw std::string{ "�� ������� ������� ���� ��� ������� ��������" };
	}

	string text{};
	string stringBuff{};

	while (getline(inputStream, stringBuff)) {
		text += stringBuff + "\n";
	}
	inputStream.close();

	return text;
}

string FileInput::InputSymbols() {

	string dir;
	do {
		cout << "������� ���� ���������� �����: ";
		dir = ConsoleInputValidation::GetString();
	} while (!CheckValidDir(dir));

	ifstream inputStream{};

	inputStream.open(dir);
	if (!inputStream.is_open()) {
		inputStream.close();
		throw std::string{ "�� ������� ������� ���� ��� ������� ��������" };
	}

	string symbols{};
	string stringBuff{};

	while (getline(inputStream, stringBuff)) {
		symbols += stringBuff;
	}
	inputStream.close();

	symbols = Symbols::GetUniqueSymbols(symbols);

	return symbols;
}

