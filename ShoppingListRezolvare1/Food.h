#pragma once
#include <string>
#include "Item.h"
using namespace std;
class Food :public Item
{
private:
	float quantity;
public:
	void setQuantity(float quantity);
	string getInfo() override;
};

