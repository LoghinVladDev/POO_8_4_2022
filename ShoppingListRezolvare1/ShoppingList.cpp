#include "ShoppingList.h"
#include "Item.h"
#include <iostream>
void ShoppingList::addItem(Item* item)
{
	this->pointerList.push_back(item);
}

void ShoppingList::printList()
{
	for (auto e : pointerList)
		std::cout << e->getInfo();
}
