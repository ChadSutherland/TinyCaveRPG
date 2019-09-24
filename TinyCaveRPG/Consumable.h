// Felipe Oliveira
// 5/12/2019
#pragma once
#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include "Item.h"

class Consumable : public Item {
private:
public:
	Consumable(string description, int value);
	Consumable(string description, int value, Position pos);
	virtual string toString() = 0;
	virtual void serialize(fstream &os) = 0;
};

#endif