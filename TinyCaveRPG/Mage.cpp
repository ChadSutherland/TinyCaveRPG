// Chad Sutherland
// 5/12/2019
#include "Mage.h"
#include "Hero.h"

Mage::Mage() : Hero() {
	setMaxHP(7);
	setCurrentHP(7);
}

Mage::Mage(int maxHP, int currentHP, Position currentPos) : Hero(maxHP, currentHP, currentPos) {

}

string Mage::toString() {
	return ("The Mage is level " + to_string(getCurrentLevel()) + " and has " + to_string(getCurrentHealth()) + "/" + to_string(getMaxHealth()) + " health points and does " + to_string(getDamage()) + " damage.\n");
}