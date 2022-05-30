#include "Hexazecimal.h"
#include <iostream>
std::string Hexazecimal::GetFormatName() {
	std::string str = "Hexadecimal";
	return str;
}
std::string Hexazecimal::FormatNumber(int number) {
	int rest = 0;
	std::string str="";
	while (number) {
		rest = number % 16;
		if (rest >= 0 && rest <= 9) {
			str.push_back((char)('0' + rest));
		}
		else {
			str.push_back((char)('A' + rest - 10));
		}
		number /= 16;
		
	}
	std::string str_2="";
	for (int i = str.length() - 1; i != -1; i--) {
		str_2.push_back(str[i]);
	}
	return str_2;
}