#pragma once
#include <string>
using namespace std;
class Item
{
private:
	string name;
public:
	string getName();
	virtual string getInfo() = 0;
	void setName(string name);
};

