// Felipe Oliveira
// 5/12/2019
#include "Item.h"
#include "Consumable.h"

Consumable::Consumable(string description, int value) : Item(description, value) {
}

Consumable::Consumable(string description, int value, Position pos) 
		: Item(description, value, pos) {
}
