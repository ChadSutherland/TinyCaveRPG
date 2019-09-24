// Felipe Oliveira
// 5/12/2019
#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

class Weapon : public Item {
private:
public:
	Weapon(string description, int value);
	Weapon(string description, int value, Position pos);
	
	virtual string toString() = 0;
	virtual void serialize(fstream &os) = 0;
};

#endif