#include <iostream>
#include "Decimal.h"
#include "Hexazecimal.h"
#include "Number.h"
#include "Printer.h"
#include <iomanip>
int main()
{
	Number n1(1), n2(2), n3(10);
	Number n4((int)((((n1 + n2) * n3) / n2) + (n1 - n2)));
	(n4.operator+=(new Hexazecimal())) 
		+= (new Decimal());
	n4.Print();
	std::cout << "Valoarea hexazecimala este: 0x" <<
		std::hex << std :: setw(8) << std :: setfill ('0') << std::uppercase
		<< (int)n4 << std::endl;
	return 0;
}
