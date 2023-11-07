#include "Words.h"

vector<string> Words::FindWordsWithSymbols(string& text, string& symbols) {

	vector<string> exeptions{};
	if (text.empty()) {
		exeptions.push_back("Отсутствует текст");
	}

	if (symbols.empty()) {
		exeptions.push_back("Отсутствуют символы");
	}

	if (!exeptions.empty()) {
		exeptions.push_back("Выполнить поставленную задачу невозможно");
		throw exeptions;
	}

	vector<string> words = GetWords(text);

	vector<int> wordsIndexToRemove{};

	set<string> wordsWithSymbolsSet{};

	try {
		for (int i = 0; i < symbols.length(); i++) {
			for (int j = 0; j < words.size(); j++) {
				if (Contains(words[j], symbols[i])) {
					wordsWithSymbolsSet.insert(words[j]);
					wordsIndexToRemove.push_back(j);
				}
			}
			RemoveWords(words, wordsIndexToRemove);
			wordsIndexToRemove.clear();
			if (words.empty()) break;
		}
	}
	catch (string ex) {
		exeptions.push_back(ex);
		throw exeptions;
	}
	vector<string> wordsWithSymbols(wordsWithSymbolsSet.begin(), wordsWithSymbolsSet.end());
	return wordsWithSymbols;
}

vector<string> Words::GetWords(string& text) {

	vector<string> words{};
	auto delim = " ,.\n";
	char* s = new char[text.size() + 1];
	strcpy_s(s, text.size()+1, text.c_str());

	char* word = NULL;
	char* next_word = NULL;

	word = strtok_s(s, delim, &next_word);

	while (word != NULL) 
	{
		words.push_back(word);
		word = strtok_s(NULL, delim, &next_word);
	}

	return words;
}

bool Words::Contains(string& word, char& symbol) {

	if (word.find(symbol) != std::string::npos)
		return true;
	else
		return false;
}

void Words::RemoveWords(vector<string>& words, vector<int> wordsIndexToRemove) {
	if (wordsIndexToRemove.size() > INT_MAX)
	{
		throw string("Слишком большой текст");
	}
	int size = static_cast<int>(wordsIndexToRemove.size())-1;
	for (int i = size; i >= 0; i--) {
		words.erase(words.begin() + wordsIndexToRemove[i]);
	}
}