#pragma once
#include "Printer.h"
class Number
{
private:
	int number = 0;
	int count = 0;
	Printer* printers[100];
public:
	Number(int);
	operator std::string();
	operator int();
	Number& operator+(Number s);
	Number& operator-(Number s);
	Number& operator*(Number s);
	Number& operator/(Number s);
	void Print();
	Number& operator+=(Printer* prnt);
};

