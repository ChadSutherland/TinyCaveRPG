// Daniyar Aubekerov
// 5/12/2019
#include "Vicious.h"

Vicious::Vicious(string newName, int damage, int maxHP, Weapon* weapon) 
	: Enemy(newName, damage, maxHP, weapon) {
	isAggressive = true;
}

Vicious::Vicious(string newName, Position pos, int damage, int curHP, int maxHP, Weapon* weapon)
	: Enemy(newName, pos, damage, curHP, maxHP, weapon)
{
	isAggressive = true;
}

Vicious::~Vicious() {

}