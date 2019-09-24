// Felipe Oliveira
// 5/12/2019
#include "Axe.h"

Axe::Axe() : Weapon("axe", 3) {
	setPosition(Position(randBetween(1, 9), randBetween(1, 19)));
}

Axe::Axe(fstream &is) : Weapon("axe", 3) {
	Position pos;
	is.read(reinterpret_cast<char*>(&pos), sizeof(Position));
	setPosition(pos);
}

Axe::Axe(Position pos)
	: Weapon("axe", 3, pos) {
}

void Axe::serialize(fstream &os) {
	int id = getID();
	Position pos = getPosition();
	os.write(reinterpret_cast<char*>(&id), sizeof(int));
	os.write(reinterpret_cast<char*>(&pos), sizeof(Position));
}