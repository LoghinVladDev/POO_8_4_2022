#pragma once
#include "Printer.h"
class Hexazecimal :
    public Printer
{
public:
    std::string GetFormatName() override;
    std::string FormatNumber(int number) override;
};

