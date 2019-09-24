// Daniyar Aubekerov
// 5/12/2019
#include "Benign.h"

Benign::Benign(string newName, int damage, int maxHP, Weapon* weapon)
	: Enemy(newName, damage, maxHP, weapon) {
	isAggressive = false;
}

Benign::Benign(string newName, Position pos, int damage, int curHP, int maxHP, Weapon* weapon)
	: Enemy(newName, pos, damage, curHP, maxHP, weapon)
{
	isAggressive = false;
}

Benign::~Benign() {

}