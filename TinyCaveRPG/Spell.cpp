// Felipe Oliveira
// 5/12/2019
#include "Weapon.h"
#include "Spell.h"

Spell::Spell(string description, int value, Position pos) : Weapon(description, value, pos) {

}

Spell::~Spell() {

}

string Spell::toString() {
	return getDescription();
}