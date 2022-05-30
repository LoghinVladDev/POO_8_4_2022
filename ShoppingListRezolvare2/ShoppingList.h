#pragma once
#include "Item.h"
#include "Miscellaneous.h"
#include "Food.h"
#include <vector>
class ShoppingList
{
private:
	std::vector<Item*> list;
public:
	void addItem(Item* c);
	void printList();
};

