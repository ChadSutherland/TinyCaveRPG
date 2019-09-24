// Felipe Oliveira
// 5/12/2019
#include "Item.h"
#include "Hero.h"
#include "Position.h"
#include "Map.h"
#include <fstream>

Item* Item::deserialize(fstream &is) {
	int itemID;
	is.read(reinterpret_cast<char*>(&itemID), sizeof(int));
	switch (itemID) {
	case 1: return new Water(is); break;
	case 2: return new Potion(is); break;
	case 3: return new Bread(is); break;
	case 4: return new Steak(is); break;
	case 5: return new Sword(is); break;
	case 6: return new Axe(is); break;
	default: return nullptr; break;
	}
}

Item::Item(string description, int value) {
	setDescription(description);
	setValue(value);
	setPosition(Position(1,1));
}

Item::Item(string description, int value, Position pos) {
	setDescription(description);
	setValue(value);
	setPosition(pos);
}

int Item::randBetween(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

bool Item::operator == (Item &right) {
	bool isEqual = false;
	if (getDescription() == right.getDescription() && getPosition() == right.getPosition())
		isEqual = true;
	return isEqual;
}

bool Item::operator != (Item &right) {
	bool isNotEqual = true;
	if (getDescription() == right.getDescription() && getPosition() == right.getPosition())
		isNotEqual = false;
	return isNotEqual;
}