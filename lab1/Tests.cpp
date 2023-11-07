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
		return "Тест №1 не пройден. Тест на пустые значения теста и символов\n";
	}
	return "";
}

string Tests::Test2() {
	auto wordsService = new Words();
	string text = "Тестовый текст из нескольких слов из букв ага";
	string symbols = "зкл";
	vector<string> result{};
	try {
		result = wordsService->FindWordsWithSymbols(text, symbols);
	}
	catch (const vector<string> ex)
	{
		return "Тест №2 не пройден. Тест на текст в одну строку\n";
	}
		
	if (result.size() == 5) {
		if (std::find(result.begin(), result.end(), "текст") != result.end() && 
			std::find(result.begin(), result.end(), "нескольких") != result.end() &&
			std::find(result.begin(), result.end(), "букв") != result.end() &&
			std::find(result.begin(), result.end(), "слов") != result.end() &&
			std::find(result.begin(), result.end(), "из") != result.end()) {
			return "";
		}
	}
	return "Тест №2 не пройден. Тест на текст в одну строку\n";
}
string Tests::Test3() {
	auto wordsService = new Words();
	string text = "Тестовый текст из нескольких слов из букв\nи строк";
	string symbols = "зкл";
	vector<string> result{};
	try {
		result = wordsService->FindWordsWithSymbols(text, symbols);
	}
	catch (const vector<string> ex)
	{
		return "Тест №3 не пройден. Тест на текст в две строки\n";
	}
		
	if (result.size() == 6) {
		if (std::find(result.begin(), result.end(), "текст") != result.end() && 
			std::find(result.begin(), result.end(), "нескольких") != result.end() &&
			std::find(result.begin(), result.end(), "букв") != result.end() &&
			std::find(result.begin(), result.end(), "слов") != result.end() &&
			std::find(result.begin(), result.end(), "строк") != result.end() &&
			std::find(result.begin(), result.end(), "из") != result.end()) {
			return "";
		}
	}
	return "Тест №3 не пройден. Тест на текст в две строки\n";
}

string Tests::Test4() {
	auto wordsService = new Words();
	string text = "Тест0вый текст из нескольких слов из букв,\nстрок и слов с цифрами как 4асти сл0в";
	string symbols = "з0";
	vector<string> result{};
	try {
		result = wordsService->FindWordsWithSymbols(text, symbols);
	}
	catch (const vector<string> ex)
	{
		return "Тест №4 не пройден. Тест на текст с цифрами в словах\n";
	}

	if (result.size() == 3) {
		if (std::find(result.begin(), result.end(), "Тест0вый") != result.end() &&
			std::find(result.begin(), result.end(), "сл0в") != result.end() &&
			std::find(result.begin(), result.end(), "из") != result.end()) {
			return "";
		}
	}
	return "Тест №4 не пройден. Тест на текст с цифрами в словах\n";
}

string Tests::Test5() {
	auto wordsService = new Words();
	string text = "Тестовый текст из нескольких слов из букв,\nно слов с символами нет(((";
	string symbols = "ящ";
	vector<string> result{};
	try {
		result = wordsService->FindWordsWithSymbols(text, symbols);
	}
	catch (const vector<string> ex)
	{
		return "Тест №5 не пройден. Тест на текст без заданных символов\n";
	}

	if (result.size() == 0) {
		return "";
	}
	return "Тест №5 не пройден. Тест на текст без заданных символов\n";
}

void Tests::RunTests() {
	string fails{};
	fails += Test1();
	fails += Test2();
	fails += Test3();
	fails += Test4();
	fails += Test5();

	if (fails.empty()) {
		cout << "Тесты пройдены" << endl;
		return;
	}

	cout << "Тесты не пройдены" << endl << fails;
}