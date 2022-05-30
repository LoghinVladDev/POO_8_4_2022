#pragma once
#include <string>
class Item
{
private:
	std::string name;
public:
	std::string getName();
	virtual std::string getInfo()=0;
	void setName(std::string name);
};

