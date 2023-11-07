#include "Symbols.h"

namespace SymbolsExt {
	string Symbols::GetUniqueSymbols(string& str) {

		set<char> symbols{};

		for (int i = 0; i < str.length(); i++) {
			symbols.insert(str[i]);
		}

		string symbolsStr(symbols.begin(), symbols.end());
		return symbolsStr;
	}
}