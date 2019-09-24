// Felipe Oliveira
// 5/12/2019
#include "Water.h"

Water::Water() : Drink("water", 1) {
	setPosition(Position(randBetween(1, 9), randBetween(1, 19)));
}

Water::Water(fstream &is) : Drink("water", 1) {
	Position pos;
	is.read(reinterpret_cast<char*>(&pos), sizeof(Position));
	setPosition(pos);
}

Water::Water(string description, int value, Position pos) : Drink(description, value, pos) {
}

void Water::serialize(fstream &os) {
	int id = getID();
	Position pos = getPosition();
	os.write(reinterpret_cast<char*>(&id), sizeof(int));
	os.write(reinterpret_cast<char*>(&pos), sizeof(Position));
}