// Felipe Oliveira
// 5/12/2019
#pragma once
#ifndef ITEM_H
#define ITEM_H
#include "Position.h"
#include <string>

class Item {
private:
	string description;
	int value;
	Position position;
public:
	static Item* deserialize(fstream &is);

	Item(string description, int value);
	Item(string description, int value, Position pos);
	
	void setPosition(Position newPos) { position = newPos; }
	void setDescription(string newDescription) { description = newDescription; }
	void setValue(int value) { this->value = value; }

	string getDescription() { return description; }
	int getValue() { return value; }
	Position getPosition() { return position; }

	int randBetween(int min, int max);

	virtual string toString() = 0;
	virtual void serialize(fstream &os) = 0;

	bool operator == (Item &right);
	bool operator != (Item &right);
};
#endif