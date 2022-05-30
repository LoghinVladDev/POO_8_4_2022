#include "Miscellaneous.h"
#include "Item.h"
string Miscellaneous::getInfo() {
	return this->getName() + " : " + to_string(this->count) + "items";
}
void Miscellaneous::setCount(int count) {
	this->count = count;
}