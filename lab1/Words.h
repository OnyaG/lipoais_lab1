#pragma once
#include <string>
#include <vector>
#include <set>

using namespace std;

class Words {
private:
	vector<string> GetWords(string& text);
	bool Contains(string& word, char& symbol);
	void RemoveWords(vector<string>& words, vector<int> wordsIndexToRemove);
public:
	vector<string> FindWordsWithSymbols(string& text, string& symbols);
};