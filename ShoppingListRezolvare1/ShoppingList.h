#pragma once
#include "Item.h"
#include <list>

class ShoppingList
{
private: 
	std::list <Item*> pointerList;
public:
	void addItem(Item*);
	void printList();
};

