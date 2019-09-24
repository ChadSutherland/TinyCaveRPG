// Felipe Oliveira
// 5/12/2019
#pragma once
#ifndef SWORD_H
#define SWORD_H
#include "Weapon.h"
#include <fstream>

class Sword : public Weapon {
private:
	const static int ID = 5;
public:
	Sword();
	Sword(fstream &is);
	Sword(Position pos);
	static int getID() { return ID; }
	string toString() { return "sword"; }
	void serialize(fstream &os);
};
#endif
