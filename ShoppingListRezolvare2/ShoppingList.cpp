#include "ShoppingList.h"
#include <iostream>
#include <iomanip>
void ShoppingList::addItem(Item* c) {
	list.push_back(c);
}
void ShoppingList::printList() {
	for (auto i = this->list.begin(); i != list.end(); i++)
	{
		std::cout<< std::setprecision(3) <<(*i)->getInfo();
	}
}