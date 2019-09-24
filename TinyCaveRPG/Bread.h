// Felipe Oliveira
// 5/12/2019
#pragma once
#ifndef BREAD_H
#define BREAD_H
#include "Food.h"
#include <fstream>

class Bread : public Food {
private:
	const static int ID = 3;
public:
	Bread();
	Bread(fstream &is);
	Bread(string description, int value, Position pos);
	static int getID() { return ID; }
	string toString() { return "bread"; }
	void serialize(fstream &os);
};
#endif
