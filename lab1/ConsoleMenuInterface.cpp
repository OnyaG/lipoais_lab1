#include "ConsoleMenuInterface.h"

#pragma region ShowMenu

void ConsoleMenuInterface::ShowGreetings()
{
	system("cls");
	cout << "������������ ������ �1, ������� �14" << endl;
	cout << "��������� ������� ���� �������, 404 ������" << endl;
	cout << "����� �����. ����������� ��� �����, ����������" << endl;
	cout << "���� �� ���� �� �������� ��������� ���������." << endl;
	cout << endl;
}

void ConsoleMenuInterface::ShowMainMenu()
{
	system("cls");
	cout << "������� ����" << endl;
	cout << "�������� ���� �� �������:" << endl;
	cout << "1 - ������ �����" << endl;
	cout << "2 - ������ ��������� ��������" << endl;
	cout << "3 - ����������� ��������� �����" << endl;
	cout << "4 - �������� �� ��������� ������" << endl;
	cout << "5 - � ���������" << endl;
	cout << "6 - ����� �� ���������" << endl;
	cout << "�����: ";
}

void ConsoleMenuInterface::ShowSavingMenu() {

	cout << endl;
	cout << "���� ����������" << endl;
	cout << "�������� ���� �� �������" << endl;
	cout << "1 - �������� �������� ����� ����" << endl;
	cout << "2 - �������� �������� ������� � ����" << endl;
	cout << "3 - �������� ��������� � ����" << endl;
	cout << "4 - ��������� � ������� ����" << endl;
	cout << "�����: ";
}

void ConsoleMenuInterface::ShowInputTypeMenu() {

	cout << endl;
	cout << "���������� ��� �������� ����?" << endl;
	cout << "�������� ���� �� �������" << endl;
	cout << "1 - ����������" << endl;
	cout << "2 - ��������" << endl;
	cout << "�����: ";
}

void ConsoleMenuInterface::ShowRewriteMenu() {

	cout << endl;
	cout << "�� ������ ������������ ��������?" << endl;
	cout << "�������� ���� �� �������" << endl;
	cout << "1 - ��" << endl;
	cout << "2 - ��������� � ������� ����" << endl;
	cout << "�����: ";
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
	cout << "��� �������� � �������� ���� ������� Enter" << endl;
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
				cout << "���� �������:" << endl;
				cout << symbols << endl;
				if (!AskToRewrite()) break;
			}
			inputType = AskInputType();

			system("cls");
			symbols = inputType->InputSymbols();

			cout << endl << "���� �������:" << endl;
			cout << symbols << endl;

			AskToMainMenu();
			break;
		case TEXT:
			if (!text.empty()) {
				cout << "��� �����:" << endl;
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
			cout << endl << "��� �����:" << endl;
			cout << text << endl;

			AskToMainMenu();
			break;
		case FIND_WORDS:

			system("cls");
			try {
				result = wordsService->FindWordsWithSymbols(text, symbols);
				cout << "��� �����:" << endl;
				cout << text << endl;
				cout << "���� �������:" << endl;
				cout << symbols << endl << endl;
				if (result.size() == 0) {
					cout << "����� � ��������� ��������� �����������" << endl;
				}
				else {
					cout << "C���� c ��������� ���������:" << endl;
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
			dataToSave = "�������:\n" + symbols + "\n\n" + "�����:\n" + text + "\n\n";

			if (result.empty()) {
				dataToSave += "����� � ��������� ��������� �����������\n";
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