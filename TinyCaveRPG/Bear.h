// Daniyar Aubekerov
// 5/12/2019

#pragma once
#ifndef BEAR_H
#define BEAR_H
#include "Benign.h"
class Bear : public Benign {
private:
	const static int ID = 2;
public:
	Bear(fstream &is);
	Bear(Position pos);
	Bear(int currentHP, Position pos);

	static int getID() { return ID; }

	string toString();
	void serialize(fstream &os);
};

#endif