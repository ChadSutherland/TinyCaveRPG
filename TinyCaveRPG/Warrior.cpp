// Chad Sutherland
// 5/12/2019
#include "Warrior.h"
#include "Hero.h"

Warrior::Warrior() : Hero() {
	setBaseDamage(3);
}

Warrior::Warrior(int maxHP, int currentHP, Position currentPos) : Hero(maxHP, currentHP, currentPos) {
	setBaseDamage(3);
}

string Warrior::toString() {
	return ("The Warrior is level " + to_string(getCurrentLevel()) + " and has " + to_string(getCurrentHealth()) + "/" + to_string(getMaxHealth()) + " health points and does " + to_string(getDamage()) + " damage.\n");
}