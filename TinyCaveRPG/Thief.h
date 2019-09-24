// Daniyar Aubekerov
// 5/12/2019
#pragma once
#ifndef THIEF_H
#define THIEF_H
#include "Benign.h"
class Thief : public Benign {
private:
	const static int ID = 1;
public:
	Thief(fstream &is);
	Thief(Position pos);
	Thief(int currentHP, Position pos);

	static int getID() { return ID; }

	string toString();
	void serialize(fstream &os);
};

#endif