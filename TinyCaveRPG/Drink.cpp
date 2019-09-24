// Felipe Oliveira
// 5/12/2019
#include "Consumable.h"
#include "Drink.h"

Drink::Drink(string description, int value) : Consumable(description, value) {

}

Drink::Drink(string description, int value, Position pos)
		: Consumable(description, value, pos) {
}
