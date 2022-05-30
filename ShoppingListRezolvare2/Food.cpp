#include "Food.h"
void Food::setQuantity(float quantity) {
	this->quantity = quantity;
}
std::string Food::getInfo() {
	return this->getName() + " : " + std::to_string(this->quantity) + " kg ";
}
Food::Food() {};