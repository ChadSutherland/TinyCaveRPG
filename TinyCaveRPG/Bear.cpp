// Daniyar Aubekerov
// 5/12/2019
#include "Bear.h"
#include "Axe.h"
#include <fstream>

Bear::Bear(fstream &is) : Benign("bear", 1, 3, nullptr) {
	int currentHP;
	Position pos;
	is.read(reinterpret_cast<char*>(&currentHP), sizeof(int));
	is.read(reinterpret_cast<char*>(&pos), sizeof(Position));
	setHealth(currentHP);
	setPosition(pos);
	setWeapon(new Axe(getPosition()));
}

Bear::Bear(Position pos) : Benign("bear", pos,
	1, 3, 3, new Axe(pos))
{
}

Bear::Bear(int currentHP, Position pos) : Benign("bear", pos,
	1, currentHP, 3, new Axe(pos))
{
}

string Bear::toString() {
	return getName();
}

void Bear::serialize(fstream &os) {
	int id = getID();
	int hp = getCurrentHealth();
	Position pos = getPosition();
	os.write(reinterpret_cast<char*>(&id), sizeof(int));
	os.write(reinterpret_cast<char*>(&hp), sizeof(int));
	os.write(reinterpret_cast<char*>(&pos), sizeof(Position));
}