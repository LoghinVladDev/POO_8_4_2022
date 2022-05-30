#pragma once
#include <string>
class Printer
{
private:

public:
	virtual std::string GetFormatName() = 0;
	virtual std::string FormatNumber(int number) = 0;
};

