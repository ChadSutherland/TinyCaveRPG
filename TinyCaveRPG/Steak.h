// Felipe Oliveira
// 5/12/2019
#pragma once
#ifndef STEAK_H
#define STEAK_H
#include "Food.h"
#include <fstream>

class Steak : public Food {
private:
	const static int ID = 4;
public:
	Steak();
	Steak(fstream &is);
	Steak(string description, int value, Position pos);
	static int getID() { return ID; }
	string toString() { return "steak"; }
	void serialize(fstream &os);
};
#endif
