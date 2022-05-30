#include "Decimal.h"
std::string Decimal::GetFormatName() {
	std::string str = "Decimal";
	return str;
}
std::string Decimal::FormatNumber(int number) {
	std::string str =std::to_string(number);
	return str;
}