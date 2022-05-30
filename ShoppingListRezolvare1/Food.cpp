#include "Food.h"
void Food::setQuantity(float quantity) {
	this->quantity = quantity;
}

string Food::getInfo() {
	return this->getName() + " : " + to_string(quantity) + " kq ";
}