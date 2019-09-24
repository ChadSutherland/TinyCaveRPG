// Daniyar Aubekerov
// 5/12/2019
#include "Thief.h"
#include "Sword.h"
#include <fstream>

Thief::Thief(fstream &is) : Benign("thief", 1, 3,nullptr) {
	int currentHP;
	Position pos;
	is.read(reinterpret_cast<char*>(&currentHP), sizeof(int));
	is.read(reinterpret_cast<char*>(&pos), sizeof(Position));
	setHealth(currentHP);
	setPosition(pos);
	setWeapon(new Sword(getPosition()));
}

Thief::Thief(Position pos) : Benign("thief", pos,
	1, 3, 3, new Sword(pos))
{
}

Thief::Thief(int currentHP, Position pos) : Benign("thief", pos,
	1, currentHP, 3,new Sword(pos))
{
}

string Thief::toString() {
	return getName();
}

void Thief::serialize(fstream &os) {
	int id = getID();
	int hp = getCurrentHealth();
	Position pos = getPosition();
	os.write(reinterpret_cast<char*>(&id), sizeof(int));
	os.write(reinterpret_cast<char*>(&hp), sizeof(int));
	os.write(reinterpret_cast<char*>(&pos), sizeof(Position));
}