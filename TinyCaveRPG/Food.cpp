// Felipe Oliveira
// 5/12/2019
#include "Consumable.h"
#include "Food.h"

Food::Food(string description, int value) : Consumable(description, value) {
}

Food::Food(string description, int value, Position pos)
	: Consumable(description, value, pos) {
}