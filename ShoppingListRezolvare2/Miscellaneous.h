#pragma once
#include "Item.h"
#include <string>
class Miscellaneous :
    public Item
{
private:
    int count;
public:
    std::string getInfo() override;
    void setCount(int count);
    Miscellaneous();
};

