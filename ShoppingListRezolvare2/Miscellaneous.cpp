#include "Miscellaneous.h"
Miscellaneous::Miscellaneous() {}
void Miscellaneous::setCount(int count) {
	this->count = count;
}
std::string Miscellaneous::getInfo() {
	return this->getName() + " : " + std::to_string(this->count) + " items";
}