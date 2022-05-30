#pragma once
#include "Printer.h"
class Decimal :
    public Printer
{
public:
    std::string GetFormatName() override;
    std::string FormatNumber(int number) override;
};

