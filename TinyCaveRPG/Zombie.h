// Daniyar Aubekerov
// 5/12/2019
#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Vicious.h"
class Zombie : public Vicious {
private:
	const static int ID = 3;
public:
	Zombie(fstream &is);
	Zombie(Position pos);
	Zombie(int currentHP, Position pos);
	
	static int getID() { return ID; }

	string toString();
	void serialize(fstream &os);
};

#endif