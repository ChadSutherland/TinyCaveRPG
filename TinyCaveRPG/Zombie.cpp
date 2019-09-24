// Daniyar Aubekerov
// 5/12/2019
#include "Zombie.h"
#include "Sword.h"
#include <fstream>

Zombie::Zombie(fstream &is) : Vicious("zombie", 3, 6, nullptr) {
	int currentHP;
	Position pos;
	is.read(reinterpret_cast<char*>(&currentHP), sizeof(int));
	is.read(reinterpret_cast<char*>(&pos), sizeof(Position));
	setHealth(currentHP);
	setPosition(pos);
	setWeapon(new Sword(getPosition()));
}

Zombie::Zombie(Position pos) : Vicious("zombie", pos,
	1, 3, 3, new Sword(pos))
{
}

Zombie::Zombie(int currentHP, Position pos) : Vicious("zombie", pos,
	1, currentHP, 3, new Sword(pos))
{
}

string Zombie::toString() {
	return getName();
}

void Zombie::serialize(fstream &os) {
	int id = getID();
	int hp = getCurrentHealth();
	Position pos = getPosition();
	os.write(reinterpret_cast<char*>(&id), sizeof(int));
	os.write(reinterpret_cast<char*>(&hp), sizeof(int));
	os.write(reinterpret_cast<char*>(&pos), sizeof(Position));
}