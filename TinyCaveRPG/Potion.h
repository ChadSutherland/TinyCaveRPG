// Felipe Oliveira
// 5/12/2019
#pragma once
#ifndef POTION_H
#define POTION_H
#include "Drink.h"
#include <fstream>

class Potion : public Drink {
private:
	const static int ID = 2;
public:
	Potion();
	Potion(fstream &is);
	Potion(string description, int value, Position pos);
	static int getID() { return ID; }
	string toString() { return "potion"; }
	void serialize(fstream &os);
};
#endif