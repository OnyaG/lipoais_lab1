#pragma once
#include <string>
#include <memory>
#include "Symbols.h"


using namespace std;

class IInput {
public:
	virtual ~IInput() = default;
	virtual string InputText() = 0;
	virtual string InputSymbols() = 0;
};

class ConsoleInput final : public IInput {
public:
	string InputText() override;
	string InputSymbols() override;
};

class FileInput final : public IInput {
private:
	bool CheckValidDir(string& dir);
public:
	string InputText() override;
	string InputSymbols() override;
};