// Felipe Oliveira
// 5/12/2019
#pragma once
#ifndef AXE_H
#define AXE_H
#include "Weapon.h"
#include <fstream>

class Axe : public Weapon {
private:
	const static int ID = 6;
public:
	Axe();
	Axe(fstream &is);
	Axe(Position pos);
	static int getID() { return ID; }
	string toString() { return "axe"; }
	void serialize(fstream &os);
};
#endif
