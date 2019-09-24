// Felipe Oliveira
// 5/12/2019
#pragma once
#ifndef WATER_H
#define WATER_H
#include "Drink.h"
#include <fstream>

class Water : public Drink {
private:
	const static int ID = 1;
public:
	Water();
	Water(fstream &is);
	Water(string description, int value, Position pos);
	static int getID() { return ID; }
	string toString() { return "water"; }
	void serialize(fstream &os);
};
#endif
