#include "Item.h"
#include <string>
using namespace std;

string Item::getName() {
	return this->name;
}
void Item::setName(string name) {
	this->name = name;
}