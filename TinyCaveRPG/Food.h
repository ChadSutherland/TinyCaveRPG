// Felipe Oliveira
// 5/12/2019
#pragma once
#ifndef FOOD_H
#define FOOD_H
#include "Item.h"
#include "Consumable.h"

class Food : public Consumable {
private:
public:
	Food(string description, int value);
	Food(string description, int value, Position pos);
	virtual string toString() = 0;
	virtual void serialize(fstream &os) = 0;
};
#endif
