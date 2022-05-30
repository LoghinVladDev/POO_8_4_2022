#include "Number.h"
#include <iostream>
Number::Number(int nr) {
	this->number = nr;
}
Number::operator std::string() {
	return printers[0]->FormatNumber(this->number);
}
Number::operator int() {
	// aici ?
	return this->number;
}
Number& Number::operator+(Number s) {
	Number w = Number((int)*this);
	w.number = this->number + s.number;
	return w;;
}
Number& Number::operator-(Number s) {
	Number w = Number((int)*this);
	w.number = this->number - s.number;
	return w;
}
Number& Number::operator*(Number s) {
	Number w = Number((int)*this);
	w.number = this->number * s.number;
	return w;
}
Number& Number::operator/(Number s) {
	Number w = Number((int)*this);
	w.number = this->number / s.number;
	return w;
}
Number& Number::operator+=(Printer* prnt) {
	printers[count] = prnt;
	count++;
	return *this;
}
void Number::Print() {
	std::string format;
	std::string name;
	for (int i = 0; i < count; i++) {
		format = printers[i]->GetFormatName();
		name = printers[i]->FormatNumber(this->number);;
		std::cout << "Format: " << format << " Value: " << name << '\n';
	}
}