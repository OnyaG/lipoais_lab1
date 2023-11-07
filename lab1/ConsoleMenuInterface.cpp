#include "ConsoleMenuInterface.h"

#pragma region ShowMenu

void ConsoleMenuInterface::ShowGreetings()
{
	system("cls");
	cout << "Лабораторная работа №1, вариант №14" << endl;
	cout << "Выполнила Ташкова Анна Юрьевна, 404 группа" << endl;
	cout << "Задан текст. Распечатать все слова, содержащие" << endl;
	cout << "хотя бы один из символов заданного множества." << endl;
	cout << endl;
}

void ConsoleMenuInterface::ShowMainMenu()
{
	system("cls");
	cout << "Главное меню" << endl;
	cout << "Выберите один из пунктов:" << endl;
	cout << "1 - Задать текст" << endl;
	cout << "2 - Задать множество символов" << endl;
	cout << "3 - Распечатать требуемые слова" << endl;
	cout << "4 - Проверка на модульных тестах" << endl;
	cout << "5 - О программе" << endl;
	cout << "6 - Выход из программы" << endl;
	cout << "Выбор: ";
}

void ConsoleMenuInterface::ShowSavingMenu() {

	cout << endl;
	cout << "Меню сохранения" << endl;
	cout << "Выберите один из пунктов" << endl;
	cout << "1 - Записать исходный текст файл" << endl;
	cout << "2 - Записать исходные символы в файл" << endl;
	cout << "3 - Записать результат в файл" << endl;
	cout << "4 - Вернуться в главное меню" << endl;
	cout << "Выбор: ";
}

void ConsoleMenuInterface::ShowInputTypeMenu() {

	cout << endl;
	cout << "Консольный или файловый ввод?" << endl;
	cout << "Выберите один из пунктов" << endl;
	cout << "1 - Консольный" << endl;
	cout << "2 - Файловый" << endl;
	cout << "Выбор: ";
}

void ConsoleMenuInterface::ShowRewriteMenu() {

	cout << endl;
	cout << "Вы хотите перезаписать значение?" << endl;
	cout << "Выберите один из пунктов" << endl;
	cout << "1 - Да" << endl;
	cout << "2 - Вернуться в главное меню" << endl;
	cout << "Выбор: ";
}

#pragma endregion

#pragma region AskMenu

bool ConsoleMenuInterface::AskToRewrite()
{
	rewriteMenuItem rewriteMenuChoice;
	do {
		ShowRewriteMenu();
		rewriteMenuChoice = ConsoleInputValidation::GetRewriteMenuItem();
		switch (rewriteMenuChoice) {
		case REWRITE:
			return true;
		case BACK:
			return false;
		default:
			break;
		}
	} while (true);
}

unique_ptr<IInput> ConsoleMenuInterface::AskInputType()
{
	inputTypeMenuItem inputTypeMenuChoice;
	do {
		ShowInputTypeMenu();
		inputTypeMenuChoice = ConsoleInputValidation::GetInputTypeMenuItem();
		switch (inputTypeMenuChoice) {
		case CONSOLE_INPUT:
			return make_unique<ConsoleInput>();
		case FILE_INPUT:
			return make_unique<FileInput>();
		default:
			break;
		}
	} while (true);
}

void ConsoleMenuInterface::AskToMainMenu()
{
	cout << "Для перехода к главному меню нажмите Enter" << endl;
	string line{};
	std::getline(cin, line);
}

#pragma endregion


void ConsoleMenuInterface::RunMainMenu()
{
	ShowGreetings();
	AskToMainMenu();

	mainMenuItem mainMenuChoice;
	auto wordsService = new Words();
	string text{};
	string symbols{};

	do {
		ShowMainMenu();
		mainMenuChoice = ConsoleInputValidation::GetMainMenuItem();

		unique_ptr<IInput> inputType;
		vector<string> result{};
		Tests tests{};

		switch (mainMenuChoice) {
		case SYMBOLS:
			if (!symbols.empty()) {
				cout << "Вашы символы:" << endl;
				cout << symbols << endl;
				if (!AskToRewrite()) break;
			}
			inputType = AskInputType();

			system("cls");
			symbols = inputType->InputSymbols();

			cout << endl << "Ваши символы:" << endl;
			cout << symbols << endl;

			AskToMainMenu();
			break;
		case TEXT:
			if (!text.empty()) {
				cout << "Ваш текст:" << endl;
				cout << text << endl;
				if (!AskToRewrite()) break;
			}

			inputType = AskInputType();

			system("cls");
			try {
				text = inputType->InputText();
			}
			catch (const string& error_message)
			{
				cout << error_message << endl;
			}
			cout << endl << "Ваш текст:" << endl;
			cout << text << endl;

			AskToMainMenu();
			break;
		case FIND_WORDS:

			system("cls");
			try {
				result = wordsService->FindWordsWithSymbols(text, symbols);
				cout << "Ваш текст:" << endl;
				cout << text << endl;
				cout << "Ваши символы:" << endl;
				cout << symbols << endl << endl;
				if (result.size() == 0) {
					cout << "Слова с заданными символами отсутствуют" << endl;
				}
				else {
					cout << "Cлова c заданными символами:" << endl;
					for (int i = 0; i < result.size(); i++) {
						cout << result[i] << endl;
					}
				}
			}
			catch (const vector<string> ex)
			{
				for (int i = 0; i < ex.size(); i++) {
					cout << ex[i] << endl;
				}
			}
			RunSaveMenu(text, symbols, result);
			break;
		case UNIT_TESTS:

			system("cls");
			tests.RunTests();
			AskToMainMenu();
			break;
		case ABOUT:
			ShowGreetings();
			AskToMainMenu();
			break;
		default:
			break;
		}
	} while (mainMenuChoice != QUIT);
}

void ConsoleMenuInterface::RunSaveMenu(string& text, string& symbols, vector<string> result)
{
	savingMenuItem saveMenuChoice;
	string dataToSave{};
	SaveData save{};

	do {
		ShowSavingMenu();
		saveMenuChoice = ConsoleInputValidation::GetSavingMenuItem();

		switch (saveMenuChoice) {
		case SAVE_TEXT:

			save.Saving(text);

			break;
		case SAVE_SYMBOLS:

			save.Saving(symbols);

			break;
		case SAVE_RESULT:
			dataToSave = "Символы:\n" + symbols + "\n\n" + "Текст:\n" + text + "\n\n";

			if (result.empty()) {
				dataToSave += "Слова с заданными символами отсутствуют\n";
			}
			else {
				for (int i = 0; i < result.size(); i++) {
					dataToSave += result[i] + "\n";
				}
			}

			save.Saving(dataToSave);
			break;
		default:
			break;
		}
	} while (saveMenuChoice != SKIP);
}