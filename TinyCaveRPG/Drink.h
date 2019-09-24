// Felipe Oliveira
// 5/12/2019
#pragma once
#ifndef DRINK_H
#define DRINK_H
#include "Consumable.h"

class Drink : public Consumable {
private:
public:
	Drink(string description, int value);
	Drink(string description, int value, Position pos);
	virtual string toString() = 0;
	virtual void serialize(fstream &os) = 0;
};
#endif
