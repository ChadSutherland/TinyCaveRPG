#include "Leader.h"
#include "Hero.h"

Leader::Leader() : Hero() {
	setMaxHP(15);
	setCurrentHP(15);
}

Leader::Leader(int maxHP, int currentHP, Position currentPos) : Hero(maxHP, currentHP, currentPos) {

}

string Leader::toString() {
	return ("The Leader is level " + to_string(getCurrentLevel()) + " and has " + to_string(getCurrentHealth()) + "/" + to_string(getMaxHealth()) + " health points and does " + to_string(getDamage()) + " damage.\n");
}