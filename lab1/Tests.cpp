#include "Tests.h"

string Tests::Test1() {
	auto wordsService = new Words();
	string text{};
	string symbols{};
	vector<string> result{};
	try {
		result = wordsService->FindWordsWithSymbols(text, symbols);
	}
	catch (const vector<string> ex)
	{
		result = ex;
	}
	if (result.size() != 3) {
		return "���� �1 �� �������. ���� �� ������ �������� ����� � ��������\n";
	}
	return "";
}

string Tests::Test2() {
	auto wordsService = new Words();
	string text = "�������� ����� �� ���������� ���� �� ���� ���";
	string symbols = "���";
	vector<string> result{};
	try {
		result = wordsService->FindWordsWithSymbols(text, symbols);
	}
	catch (const vector<string> ex)
	{
		return "���� �2 �� �������. ���� �� ����� � ���� ������\n";
	}
		
	if (result.size() == 5) {
		if (std::find(result.begin(), result.end(), "�����") != result.end() && 
			std::find(result.begin(), result.end(), "����������") != result.end() &&
			std::find(result.begin(), result.end(), "����") != result.end() &&
			std::find(result.begin(), result.end(), "����") != result.end() &&
			std::find(result.begin(), result.end(), "��") != result.end()) {
			return "";
		}
	}
	return "���� �2 �� �������. ���� �� ����� � ���� ������\n";
}
string Tests::Test3() {
	auto wordsService = new Words();
	string text = "�������� ����� �� ���������� ���� �� ����\n� �����";
	string symbols = "���";
	vector<string> result{};
	try {
		result = wordsService->FindWordsWithSymbols(text, symbols);
	}
	catch (const vector<string> ex)
	{
		return "���� �3 �� �������. ���� �� ����� � ��� ������\n";
	}
		
	if (result.size() == 6) {
		if (std::find(result.begin(), result.end(), "�����") != result.end() && 
			std::find(result.begin(), result.end(), "����������") != result.end() &&
			std::find(result.begin(), result.end(), "����") != result.end() &&
			std::find(result.begin(), result.end(), "����") != result.end() &&
			std::find(result.begin(), result.end(), "�����") != result.end() &&
			std::find(result.begin(), result.end(), "��") != result.end()) {
			return "";
		}
	}
	return "���� �3 �� �������. ���� �� ����� � ��� ������\n";
}

string Tests::Test4() {
	auto wordsService = new Words();
	string text = "����0��� ����� �� ���������� ���� �� ����,\n����� � ���� � ������� ��� 4���� ��0�";
	string symbols = "�0";
	vector<string> result{};
	try {
		result = wordsService->FindWordsWithSymbols(text, symbols);
	}
	catch (const vector<string> ex)
	{
		return "���� �4 �� �������. ���� �� ����� � ������� � ������\n";
	}

	if (result.size() == 3) {
		if (std::find(result.begin(), result.end(), "����0���") != result.end() &&
			std::find(result.begin(), result.end(), "��0�") != result.end() &&
			std::find(result.begin(), result.end(), "��") != result.end()) {
			return "";
		}
	}
	return "���� �4 �� �������. ���� �� ����� � ������� � ������\n";
}

string Tests::Test5() {
	auto wordsService = new Words();
	string text = "�������� ����� �� ���������� ���� �� ����,\n�� ���� � ��������� ���(((";
	string symbols = "��";
	vector<string> result{};
	try {
		result = wordsService->FindWordsWithSymbols(text, symbols);
	}
	catch (const vector<string> ex)
	{
		return "���� �5 �� �������. ���� �� ����� ��� �������� ��������\n";
	}

	if (result.size() == 0) {
		return "";
	}
	return "���� �5 �� �������. ���� �� ����� ��� �������� ��������\n";
}

void Tests::RunTests() {
	string fails{};
	fails += Test1();
	fails += Test2();
	fails += Test3();
	fails += Test4();
	fails += Test5();

	if (fails.empty()) {
		cout << "����� ��������" << endl;
		return;
	}

	cout << "����� �� ��������" << endl << fails;
}