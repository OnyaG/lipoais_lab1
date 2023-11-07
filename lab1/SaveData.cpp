#include "SaveData.h"

using namespace std;
using namespace ConsoleValidation;

bool SaveData::AskRewrite() {
	cout << "������������ ������������ ����?" << std::endl 
		<< "1 - ��" << std::endl 
		<< "2 - ���" << std::endl;
	rewriteMenuItem saveAnswer = ConsoleInputValidation::GetRewriteMenuItem();
	if (saveAnswer == REWRITE)
		return true;
	return false;
}

bool SaveData::Check(std::string dir) {
	std::ifstream checkText;

	try {
		static_cast<void>(std::filesystem::is_regular_file(dir));
	}
	catch (...) {

		std::cout << "������ ����������! ���� � ����� �����������" << std::endl;
		return false;
	}
	checkText.open(dir);
	if (!checkText.is_open()) {
		checkText.close();
		std::cout << "������ ����� ����\n";
		return true;
	}
	else {
		std::cout << "���� ��� ����������!\n";
		checkText.close();
		return AskRewrite();
	}
	return true;
}

void SaveData::Saving(std::string& strForSave) {
	std::string dir;
	std::cout << "������� ���� ���������� �����: ";
	dir = ConsoleInputValidation::GetString();
	while (!Check(dir)) {
		return;
	}
	std::ofstream outputText;

	outputText.open(dir, std::ios_base::out);
	if (!outputText.is_open()) {
		std::cout << "������ �� �������" << std::endl;
	}
	else {
		outputText << strForSave;
		outputText.close();
	}
}