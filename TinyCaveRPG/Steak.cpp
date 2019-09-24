// Felipe Oliveira
// 5/12/2019
#include "Steak.h"

Steak::Steak() : Food("steak", 3) {
	setPosition(Position(randBetween(1, 9), randBetween(1, 19)));
}

Steak::Steak(fstream &is) : Food("steak", 3) {
	Position pos;
	is.read(reinterpret_cast<char*>(&pos), sizeof(Position));
	setPosition(pos);
}

Steak::Steak(string description, int value, Position pos)
	: Food(description, value, pos) {
}

void Steak::serialize(fstream &os) {
	int id = getID();
	Position pos = getPosition();
	os.write(reinterpret_cast<char*>(&id), sizeof(int));
	os.write(reinterpret_cast<char*>(&pos), sizeof(Position));
}