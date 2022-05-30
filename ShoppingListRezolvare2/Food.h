#pragma once
#include "Item.h"
#include <string>
class Food :
    public Item
{
private:
    float quantity;
public:
    void setQuantity(float quantity);
    std::string getInfo() override;
    Food();
};

