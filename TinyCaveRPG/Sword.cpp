// Felipe Oliveira
// 5/12/2019
#include "Sword.h"

Sword::Sword() : Weapon("sword", 2) {
	setPosition(Position(randBetween(1, 9), randBetween(1, 19)));
}

Sword::Sword(fstream &is) : Weapon("sword", 2) {
	Position pos;
	is.read(reinterpret_cast<char*>(&pos), sizeof(Position));
	setPosition(pos);
}

Sword::Sword(Position pos)
	: Weapon("sword", 2, pos) {
}

void Sword::serialize(fstream &os) {
	int id = getID();
	Position pos = getPosition();
	os.write(reinterpret_cast<char*>(&id), sizeof(int));
	os.write(reinterpret_cast<char*>(&pos), sizeof(Position));
}