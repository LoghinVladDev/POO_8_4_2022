#pragma once
#include "Item.h"
class Miscellaneous :public Item
{
private:
	int count;
public:
	string getInfo() override;
	void setCount(int count);
};

