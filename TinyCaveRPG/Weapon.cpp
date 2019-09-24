// Felipe Oliveira
// 5/12/2019
#include "Item.h"
#include "Weapon.h"

Weapon::Weapon(string description, int value)
	: Item(description, value) {
}

Weapon::Weapon(string description, int value, Position pos)
	: Item(description, value, pos) {
}