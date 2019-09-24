// Daniyar Aubekerov
// 5/12/2019
#pragma once
#ifndef ORC_H
#define ORC_H
#include "Vicious.h"
class Orc : public Vicious {
private:
	const static int ID = 4;
public:
	Orc(fstream &is);
	Orc(Position pos);
	Orc(int currentHP, Position pos);

	static int getID() { return ID; }

	string toString();
	void serialize(fstream &os);
};

#endif